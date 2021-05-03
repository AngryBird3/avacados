//
// Created by Dhara Balaji
//

#ifndef AVACADOS_MAZE_NODE_H
#define AVACADOS_MAZE_NODE_H

#include <list>

/*
 * Class for representing 2DMap cell as node.
 * Two nodes are connected if there is no obstacle between them.
 */
class MazeNode
{
public:
    /**
     *
     * @param location  grid co-ordinate for this node (cell)
     * @param val node(cell) value
     */
    MazeNode(std::pair<int, int> location, char val);

    /* Get connected nodes to this node */
    std::list<MazeNode*> getNeighbors();

    /* Add neighbor */
    void addEdge(MazeNode* node);

    /* get x co-ordinate */
    int getX() const;

    /* get y co-ordinate */
    int getY() const;

    /* get row, col of this node */
    std::pair<int, int> getXY() const;

    /* return true if node contains avacado */
    bool hasAvacado() const;

    /* removes avacado */
    void removeAvacado();

private:
    std::pair<int, int> location;
    bool containsAvacado;
    std::list<MazeNode *> neighbors;
};

#endif //AVACADOS_MAZE_NODE_H
