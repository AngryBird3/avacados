//
// Created by Dhara Balaji on 4/28/21.
//

#ifndef AVACADOS_MAZE_NODE_H
#define AVACADOS_MAZE_NODE_H

#include <list>

/*
 * Class for representing 2DMap cell as node.
 * Two nodes are connected if there is no obstacles.
 */
class MazeNode
{
public:
    MazeNode(std::pair<int, int> location, char val);

    /* Get connected nodes to this node */
    std::list<MazeNode*> getNeighbors();

    /* Add neighbor */
    void addEdge(MazeNode* node);

    /* get x co-ordinate */
    int getX();

    /* get y co-ordinate */
    int getY();

    /* return true if node contains avacado */
    bool hasAvacado();

private:
    std::pair<int, int> location;
    bool containsAvacado;
    std::list<MazeNode *> neighbors;
};

#endif //AVACADOS_MAZE_NODE_H
