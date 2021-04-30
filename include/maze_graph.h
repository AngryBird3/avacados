//
// Created by Dhara Balaji on 4/28/21.
//

#ifndef AVACADOS_MAZE_GRAPH_H
#define AVACADOS_MAZE_GRAPH_H

#include<map>
#include <vector>
#include "maze_node.h"

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
    /*
     * @params root - start node
     * @returns pair with new start node (with avacado) and its distance
     */
    std::pair<MazeNode*, int> find_shortest_path(MazeNode* root);
};

class Astar : public  TraverseMaze
{
public:
    paths find_shortest_path(MazeNode* root, int total_avacados,
                             std::vector<MazeNode*> avacados) override;

};
#endif //AVACADOS_MAZE_GRAPH_H
