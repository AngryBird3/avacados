//
// Created by Dhara Balaji on 4/28/21.
//

#ifndef AVACADOS_SHORTEST_PATH_H
#define AVACADOS_SHORTEST_PATH_H

#include<map>
#include <utility>
#include <vector>
#include "maze_node.h"

// TraverseMaze returns what is asked in the challenge
struct paths
{
public:
    int total_moves;
    std::vector<std::string> moves_for_picking_avacados;
    paths(int total_moves, std::vector<std::string> moves) : total_moves(total_moves), moves_for_picking_avacados(std::move(moves)) {}
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
    virtual ~TraverseMaze();
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
    int id;
    std::vector<std::pair<GraphNode*, int>> edges; //edge with weights

    void addEdge(GraphNode* e, int weight)
    {
        edges.emplace_back(e, weight);
    }
    void setId(int i)
    {
        id = i;
    }
};

struct Graph
{
    Graph() : start(nullptr), nodeId(0) {}
    std::vector<GraphNode *>nodes;
    GraphNode* start;
    int nodeId;

    /**
     * Add node to graph if it didn't already exist. I could have used unordered_map
     * @param location
     * @return
     */
    GraphNode* addNode(xy location)
    {
        // check if it already exists
        for (auto i : nodes)
        {
            if (i->location == location) {
                return i;
            }
        }
        auto n = new GraphNode(location);
        n->setId(nodeId); nodeId++;
        nodes.push_back(n);
        return n;
    }

    void setStartNode(GraphNode* n)
    {
        if (start == nullptr)
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

    paths find_path_visiting_all_node(const Graph& g, int toal_avacaods);
};

#endif //AVACADOS_SHORTEST_PATH_H
