//
// Created by Dhara Balaji on 4/28/21.
//

#include "shortest_path.h"
#include <queue>
#include <set>
#include <vector>
#include <string>
#include <iostream>

std::pair<MazeNode*, int> DoBFS::find_shortest_path(MazeNode* root)
{
    std::queue<std::pair<MazeNode*, int>> q;
    std::set<std::pair<int, int> > visited;

    q.push(std::make_pair(root, 0));
    MazeNode* node;
    int dist;
    while(!q.empty())
    {
        std::tie(node, dist) = q.front();
        q.pop();
        if (node->hasAvacado())
        {
            // collect avacados
            node->removeAvacado();
            return std::make_pair(node, dist);
        }

        visited.insert(node->getXY());
        std::cout << "at node: " << node->getX() << "," << node->getY() << "steps= " << dist << "\n";

        for (auto n : node->getNeighbors())
        {
            if (visited.find(n->getXY()) == visited.end()) {
                q.emplace(std::make_pair(n, dist+1));
            }
        }

    }
    /// well we shouldn't be here as there are no more avacados remaining now
//    return std::make_pair(root, 0);
    throw std::invalid_argument("no more avacados remaining!");
}

paths DoBFS::find_shortest_path(MazeNode *root, int total_avacados, std::vector<MazeNode *> avacados)
{
    std::vector<std::string> moves;
    int dist;
    int total_moves = 0;

    while (total_avacados > 0)
    {
        std::tie(root, dist) = find_shortest_path(root);
        --total_avacados;
        moves.push_back(std::string(std::to_string(root->getX()) + "," +
                        std::string(std::to_string(root->getY()))));
        total_moves += dist;
        std::cout << "[DHARA_DEBUG] reached avacado at" << root->getX() << "," << root->getY() << " .. moves=" << dist << "\n";
    }
    std::cout << "[DHARA_DEBUG] total moves = " << total_moves << "\n";
    return paths(total_moves, moves);
}