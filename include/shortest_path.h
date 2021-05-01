//
// Created by Dhara Balaji on 4/28/21.
//

#ifndef AVACADOS_SHORTEST_PATH_H
#define AVACADOS_SHORTEST_PATH_H

#include<map>
#include <vector>
#include "maze_node.h"
#include "addEdge.h"

// TraverseMaze returns what is asked in the challenge
struct paths
{
public:
    int total_moves;
    std::vector<std::string> moves_for_picking_avacados;
    paths(int total_moves, std::vector<std::string> moves) : total_moves(total_moves), moves_for_picking_avacados(moves) {}
};

// Base class
class TraverseMaze
{
public:
    /**
     *
     * @param root
     * @param total_avacados
     * @param avacados
     * @return
     */
    virtual paths find_shortest_path(MazeNode* root, int total_avacados,
                                     std::vector<MazeNode*> avacados) = 0;
};


// Use nearest neighbor approach. Hope to nearest node with avacado
// and start from there till you collect all avacados.
class DoBFS : public TraverseMaze
{
public:
    paths find_shortest_path(MazeNode* root, int total_avacados,
                             std::vector<MazeNode*> avacados) override;
private:
    // Do BFS from a node till you find closest node with avacado.
    // It updates "destination" node by removing avacado
    /**
     * @param root - start node
     * @return pair with new start node (with avacado) and its distance
     */
    std::pair<MazeNode*, int> find_shortest_path(MazeNode* root);
};

using vector2d = std::vector<std::vector<char>>;

using xy = std::pair<int, int>;
using edge = std::pair<xy, int>;

struct GraphNode
{
    GraphNode(xy loc) : location(loc) {}
    xy location;
    std::list<edge> edges; //edge with weights

    void addEdge(edge e)
    {
        edges.push_back(e);
    }
};

struct Graph
{
    Graph() : start(nullptr) {}
    std::list<GraphNode *>nodes;
    GraphNode* start;

    void addNode(GraphNode* n)
    {
        // check if it already exists
        for (auto i : nodes)
        {
            if (i->location == n->location) {
                return;
            }
        }
        nodes.push_back(n);
    }
    void setStartNode(GraphNode* n)
    {
        if (start != nullptr)
            start = n;
    }
};

class DoAstar : public  TraverseMaze
{
public:
    DoAstar(vector2d g, int rows, int cols) : grid(g), rows(rows), cols(cols) {}
    /**
     *
     * @param root
     * @param total_avacados
     * @param avacados
     * @return
     */
    paths find_shortest_path(MazeNode* root, int total_avacados,
                             std::vector<MazeNode*> avacados) override;

private:
    vector2d grid;
    int rows;
    int cols;

    paths find_path_visiting_all_node(const Graph& g);
};

#endif //AVACADOS_SHORTEST_PATH_H
