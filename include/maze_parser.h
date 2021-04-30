//
// Created by Dhara Balaji on 4/28/21.
//

#ifndef AVACADOS_MAZE_PARSER_H
#define AVACADOS_MAZE_PARSER_H

#include <map>
#include "maze_node.h"
#include <vector>

// Class for representing floor (2DMap grid) with obstacles, start point and avacadoes
class MazeParser
{
public:
    // Constructs MazeGraph
    MazeParser(std::string inputFile);

    MazeNode* getRootNode();
    int getNumOfAvacados();
    std::vector<MazeNode*> getAvacadoNodes();

private:
    void addNode(int row, int col, char c);
    void buildGraph();
    void addAdjustNode(int r, int c);

    MazeNode* root;
    std::map<std::pair<int, int>, MazeNode*> node_map;
    int rows;
    int cols;
    int avacados = 0;
};
#endif //AVACADOS_MAZE_PARSER_H
