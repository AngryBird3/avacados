//
// Created by Dhara Balaji on 4/30/21.
//
#include <functional>
#include <A*.h>
#include <cmath>
#include <iostream>

uint64_t Astar::euclidean(xy src, xy dest)
{
    auto d = std::make_pair(abs(src.first - dest.first), abs(src.second - dest.second));
    return std::sqrt(std::pow(d.first, 2)) + std::pow(d.second, 2);
}

uint64_t Astar::manhattan(xy src, xy dest)
{
    return abs(src.first - dest.first) + abs(src.second - dest.second);
}

xy Astar::getNeighbor(std::pair<int, int> pair, int i) {
    switch (i) {
        case 0:
            // move up;
            return std::make_pair(pair.first, pair.second - 1);
        case 1:
            // move down;
            return std::make_pair(pair.first, pair.second + 1);
        case 2:
            // move left;
            return std::make_pair(pair.first - 1, pair.second);
        default:
            //move right;
            return std::make_pair(pair.first + 1, pair.second);
    }
}

/**
 * Why would I not be able to iterator after iterating through entire vector?
 * May be try with index like beign() + index
 * @param nodes
 * @return
 */
std::vector<AStarNode *>::iterator Astar::findNodeWithLeastFScore(std::vector<AStarNode *> nodes) {
    auto curr = INT64_MAX;
    auto p = nodes.begin();
    for (auto i = nodes.begin(); i < nodes.end(); i++)
    {
        auto n = *i;
        if (n->getScore() <= curr)
        {
            curr = n->getScore();
            p = i;
        }
    }
    return p;
}

bool Astar::safe(xy pair) {
    return pair.first < rows && pair.second < cols &&
                pair.first >= 0 && pair.second >= 0 && grid[pair.first][pair.second] != '#';
}

AStarNode *Astar::findNodeInOpen(std::vector<AStarNode *> nodes, std::pair<int, int> pair) {
    for (auto n : nodes)
    {
        if (n->xy == pair) {
            return n;
        }
    }
    return nullptr;
}

int64_t Astar::findPath(std::pair<int, int> src, std::pair<int, int> dest)
{
    // I can't use priority queue because I need to go through my queue and remove cur
    auto comparator = [](AStarNode *a, AStarNode* b)
    {
        return a->getScore() > b->getScore();
    };
//    std::priority_queue<AStarNode*, std::vector<AStarNode*>, decltype(comparator)> open(comparator);

    std::vector<AStarNode*> open;
    std::vector<AStarNode*> closed;

    open.push_back(new AStarNode(src));

    while (!open.empty())
    {
        // get the node with least F score
//        auto current_it = findNodeWithLeastFScore(open);
//        auto current = *current_it;

        auto p = open.begin();
        auto current = *p;
        for (auto i = open.begin(); i < open.end(); i++)
        {
            auto n = *i;
            if (n->getScore() <= current->getScore())
            {
                current = n;
                p = i;
            }
        }

        // if found destination return cost to reach this node
        if (current->xy == dest) {
            return current->g_cost;
        }

        // add to close and remove cur
        closed.push_back(current);
        open.erase(p);

        for(int i = 0; i < 4; i++)
        {
            auto neighborXY = getNeighbor(current->xy, i);
            if (!safe(neighborXY))
                continue;
            uint64_t total_cost = current->g_cost + 1; //for this problem the cost is always +1
            // let's see if we have in our openList
            AStarNode* next = findNodeInOpen(open, neighborXY);
            if (next != nullptr) {
                // update neighbor cost if we should
                if (total_cost < next->g_cost) {
                    next->g_cost = total_cost;
                }
            } else {
                next = new AStarNode(neighborXY);
                next->g_cost = total_cost;
                next->h_cost = euclidean(neighborXY, dest);
                open.push_back(next);
            }
        }
    }
    return INT64_MAX;
}

uint64_t AStarNode::getScore() {
    return g_cost + h_cost;
}
