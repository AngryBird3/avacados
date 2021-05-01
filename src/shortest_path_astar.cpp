//
// Created by dhara on 4/30/21.
//

#include "shortest_path.h"
#include "A*.h"

/**
 *
 * intuition
 *
 * 1. Find shortest distance using A* to/from src to avacados and avacados to avacados
 * 2. Create graph using 1
 * 3. Now you have graph from which start at src and visit all nodes with shortest path
 */
paths DoAstar::find_shortest_path(MazeNode *root, int total_avacados, std::vector<MazeNode *> avacados)
{
    Astar a = Astar(grid, rows, cols);

    Graph g;

    for (int i = 0; i < avacados.size(); i++)
    {
        auto d = a.findPath(root->getXY(), avacados[i]->getXY());
        if (d != INTMAX_MAX)
        {
            auto src = new GraphNode(root->getXY());
            auto dest = new GraphNode(avacados[i]->getXY());
            g.addNode(src);
            g.setStartNode(src);
            g.addNode(dest);
            src->addEdge(std::make_pair(dest->location, d));
            dest->addEdge(std::make_pair(src->location, d));
        }
        for (int j = i+1; j < avacados.size(); j++)
        {
            auto d = a.findPath(avacados[i]->getXY(), avacados[j]->getXY());
            auto src = new GraphNode(avacados[j]->getXY());
            auto dest = new GraphNode(avacados[i]->getXY());
            g.addNode(src);
            g.addNode(dest);
            src->addEdge(std::make_pair(dest->location, d));
            dest->addEdge(std::make_pair(src->location, d));
        }
    }
    return find_path_visiting_all_node(g);
}

paths DoAstar::find_path_visiting_all_node(const Graph &g)
{

}
