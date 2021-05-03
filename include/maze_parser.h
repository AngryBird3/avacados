//
// Created by Dhara Balaji
//

#ifndef AVACADOS_MAZE_PARSER_H
#define AVACADOS_MAZE_PARSER_H

#include <map>
#include "maze_node.h"
#include <vector>

// should have used namespace
using vector2d = std::vector<std::vector<char>>;

// Class for representing floor/maze (2DMap grid) with obstacles, start point and avacadoes
class MazeParser
{
public:
    // Constructs MazeGraph
    MazeParser(std::string inputFile);

    /**
     *
     * @return  start node marked as x in our grid
     */
    MazeNode* getRootNode();

    /**
     *
     * @return num of avacados in grid
     */
    int getNumOfAvacados() const;

    /**
     *
     * @return avacado "node" in our graph
     */
    std::vector<MazeNode*> getAvacadoNodes();

    /**
     *
     * @return gets the input as 2d vector rather than graph
     */
    vector2d getGrid();

    /**
     * max num of rows in grid
     */
    size_t getRows() const;

    /**
     * max num of cols in grid
     */
    size_t getCols() const;

private:
    void addNode(int row, int col, char c);
    void buildGraph();
    void addAdjustNode(int r, int c);

    MazeNode* root;
    std::map<std::pair<int, int>, MazeNode*> node_map;
    size_t rows;
    size_t cols;
    int avacados = 0;
    vector2d grid;
    std::vector<MazeNode*> avacadoNodes;

    void printGrid(vector2d vector);
};
#endif //AVACADOS_MAZE_PARSER_H
