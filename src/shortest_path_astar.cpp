//
// Created by dhara on 4/30/21.
//

#include "shortest_path.h"
#include "A*.h"
#include <set>
#include <unordered_map>
#include <string>
#include <iostream>
#include <utility>
/**
 *
 * intuition
 *
 * 1. Find shortest distance using A* to/from src to avacados and avacados to avacados
 * 2. Create graph using 1
 * 3. Using graph from 2, start at src and visit all nodes using modified Dijkstra which also stores
 *    visited mask
 */
paths DoAstar::find_shortest_path(MazeNode *root, int total_avacados, std::vector<MazeNode *> avacados)
{
    // Init Astar
    Astar a = Astar(grid, rows, cols);

    Graph g;

    // Step 1 - build graph with our important nodes- start and all avacados
    std::cout << "[step1] building graph through Astar using only start and avacado nodes\n";
    for (int i = 0; i < avacados.size(); i++)
    {
        // create edge between start(x) to avacado[i]
        int64_t d = a.findPath(root->getXY(), avacados[i]->getXY());
        if (d != INT64_MAX)
        {
            auto src = g.addNode(root->getXY());
            auto dest = g.addNode(avacados[i]->getXY());
            g.setStartNode(src);
            src->addEdge(dest, d);
            dest->addEdge(src, d);
        }
        for (int j = i+1; j < avacados.size(); j++)
        {
            auto d = a.findPath(avacados[i]->getXY(), avacados[j]->getXY());
            if (d != INT64_MAX)
            {
                auto src = g.addNode(avacados[j]->getXY());
                auto dest = g.addNode(avacados[i]->getXY());
                src->addEdge(dest, d);
                dest->addEdge(src, d);
            }
        }
    }
//    std::cout << "[DHARA_DEBUG: shortest_path_astar] << done with step1\n";
//    std::cout << "[DHARA_DEBUG] start node's edges are ...\n";
//    for (auto n : g.nodes)
//    {
//        std::cout << "node= ";
//        std::cout << n->location.first << "," << n->location.second << "\n";
//        std::cout << "      edges = ";
//        for (auto e : n->edges)
//        {
//            std::cout << e.first->location.first << "," << e.first->location.second << ", ";
//        }
//        std::cout << "\n";
//    }
    // step2
    return find_path_visiting_all_node(g, total_avacados);
}

struct state
{
    GraphNode* cur;
    int visited_mask;
    std::vector<std::string> visited;
    int total_distance; // took these many steps

    state(GraphNode* cur, int total_distance, int visited_mask) : cur(cur),
            total_distance(total_distance), visited_mask(visited_mask) {}

    void addVisited(GraphNode* n)
    {
        visited.push_back(std::to_string(n->location.first) + ',' + std::to_string(n->location.second));
    }
};

paths DoAstar::find_path_visiting_all_node(const Graph &g, int total_avacados)
{

    std::list<state> q;
    auto all_visited = (1 << (total_avacados+1)) - 1;
    auto start_state = state(g.start, 0, 1 << g.start->id);
    start_state.addVisited(g.start);

    q.push_back(start_state);
    std::vector<state> result;
    // keeps track of cost for each node WITH state=visited mask (nodes visited)
    std::unordered_map<int, std::unordered_map<int, int>> cost;

    while (!q.empty())
    {
        auto s = q.front(); q.pop_front();
        if (s.visited_mask == all_visited)
        {
            result.push_back(s);
            continue;
        }

        auto neighbors = s.cur->edges;
        for (auto v: neighbors)
        {
            auto cur_bitmask = s.visited_mask;
            auto bitmask = cur_bitmask | (1 << v.first->id);

            // check cost[node][visited_bitmask] >= cur_total_distance + weight[cur][node], then update
            if (cost.find(v.first->id) == cost.end() || cost[v.first->id].find(bitmask) == cost[v.first->id].end()
                                ||  s.total_distance + v.second <= cost[v.first->id][bitmask]) {
                // branch out - put them in the queue
                auto n_s = state(v.first, s.total_distance + v.second, bitmask);
                n_s.visited = s.visited;
                n_s.addVisited(v.first);
                q.push_back(n_s);
                // cost to reach to this neighbor (and bitmask/path so we don't go in loop)
                cost[v.first->id][bitmask] = s.total_distance + v.second;
            }
        }
    }

    // so now we have num of states which contains path with various cost. Let's find the min
    auto min_cost = INT64_MAX;
    std::vector<std::string>  moves;

    for (auto r : result)
    {
        if (r.total_distance < min_cost)
        {
            min_cost = r.total_distance;
            moves = r.visited;
        }
    }
    return paths(min_cost, moves);
}

