//
// Created by Dhara Balaji on 4/28/21.
//

#include "maze_parser.h"
#include <fstream>
#include <iostream>

MazeParser::MazeParser(std::string inputFile)
{
    std::ifstream ifs(inputFile);
    std::string s;
    int row = 0, col = 0;

    if (!ifs.is_open()) {
        throw std::invalid_argument("unable to open file");
    }

    while(ifs >> s) {
        cols = s.size();
        col = 0;
        grid.resize(row+1);
        grid[row].resize(cols);
        for (const auto c : s)
        {
            grid[row][col] = c;
            if (c != '#')
            {
                addNode(row, col, c);
            }
            ++col;
        }
        ++row;
    }
    rows = row;
    printGrid(grid);
    buildGraph();
}

void MazeParser::printGrid(vector2d grid)
{
    for (int i = 0; i < getRows(); i++)
    {
        for (int j = 0; j < getCols(); j++)
        {
            std::cout << grid[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void MazeParser::buildGraph()
{
    for (auto node : node_map)
    {
        addAdjustNode(node.second->getX(), node.second->getY());
    }
}

void MazeParser::addNode(int row, int col, char c)
{
    auto p = std::make_pair(row, col);
    node_map[p] = new MazeNode(p, c);
    if (c == 'x')
    {
        root = node_map[p];
    }
    if (c == '@') // TODO make them global constant
    {
        ++avacados;
        avacadoNodes.push_back(node_map[p]);
    }
}

int MazeParser::getNumOfAvacados()
{
    return avacados;
}

void MazeParser::addAdjustNode(int r, int c)
{
    auto p = std::make_pair(r, c);
    // top
    if (r-1 >= 0 && node_map.find(std::make_pair(r-1, c)) != node_map.end())
    {
        node_map[p]->addEdge(node_map[std::make_pair(r-1, c)]);
    }
    // bottom
    if (r + 1 < rows && node_map.find(std::make_pair(r+1, c)) != node_map.end())
    {
        node_map[p]->addEdge(node_map[std::make_pair(r + 1, c)]);
    }
    // left
    if (c - 1 >= 0 && node_map.find(std::make_pair(r, c - 1)) != node_map.end())
    {
        node_map[p]->addEdge(node_map[std::make_pair(r, c - 1)]);
    }
    // right
    if (c + 1 < cols && node_map.find(std::make_pair(r, c+1)) != node_map.end())
    {
        node_map[p]->addEdge(node_map[std::make_pair(r, c+1)]);
    }
}

MazeNode* MazeParser::getRootNode()
{
    return root;
}

vector2d MazeParser::getGrid()
{
    return grid;
}

size_t MazeParser::getRows()
{
    return rows;
}

size_t MazeParser::getCols()
{
    return cols;
}

std::vector<MazeNode *> MazeParser::getAvacadoNodes() {
    return avacadoNodes;
}
