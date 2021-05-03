//
// Created by Dhara Balaji on 4/28/21.
//

#include "maze_node.h"

// This file contains Node definition for maze which is used to traverse maze as graph through BFS

/**
 *
 * @param location cell (row, col)
 * @param val value of cell
 */
MazeNode::MazeNode(std::pair<int, int> location, char val)
{
    this->location = location;
    this->containsAvacado = (val == '@');
}

/**
 *
 * @param node neighbor node
 */
void MazeNode::addEdge(MazeNode* node)
{
    this->neighbors.emplace_back(node);
}

std::list<MazeNode*> MazeNode::getNeighbors()
{
    return neighbors;
}

int MazeNode::getX() const
{
    return location.first;
}

int MazeNode::getY() const
{
    return location.second;
}

std::pair<int, int> MazeNode::getXY() const
{
    return location;
}

bool MazeNode::hasAvacado() const
{
    return containsAvacado;
}

void MazeNode::removeAvacado()
{
    containsAvacado = false;
}
