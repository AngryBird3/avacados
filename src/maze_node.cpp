//
// Created by Dhara Balaji on 4/28/21.
//

#include "maze_node.h"
#include <iostream>


MazeNode::MazeNode(std::pair<int, int> location, char val)
{
    this->location = location;
    this->containsAvacado = (val == '@');
}

void MazeNode::addEdge(MazeNode* node)
{
    this->neighbors.emplace_back(node);
}

std::list<MazeNode*> MazeNode::getNeighbors()
{
    return neighbors;
}

int MazeNode::getX()
{
    return location.first;
}

int MazeNode::getY()
{
    return location.second;
}

std::pair<int, int> MazeNode::getXY()
{
    return location;
}

bool MazeNode::hasAvacado()
{
    return containsAvacado;
}

void MazeNode::removeAvacado()
{
    containsAvacado = false;
}
