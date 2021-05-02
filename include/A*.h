//
// Created by dhara on 4/30/21.
//

#ifndef AVACADOS_A_H
#define AVACADOS_A_H

#include <vector>
#include <queue>

using vector2d = std::vector<std::vector<char>>;
using xy = std::pair<int, int>;

struct AStarNode
{
public:
    AStarNode(std::pair<int, int> xy) : xy(xy), g_cost(0), h_cost(0) {}
    uint64_t g_cost, h_cost;
    std::pair<int, int> xy;

    uint64_t getScore();
};


class Astar
{
public:
    Astar(vector2d grid, int rows, int cols) :grid(grid), rows(rows), cols(cols) {}

    /* returns just the cost rather than entire path */
    int64_t findPath(std::pair<int, int> src, std::pair<int, int> dest);

private:
    vector2d grid;
    int rows, cols;
    uint64_t euclidean(xy src, xy dest);

    xy getNeighbor(std::pair<int, int> pair, int i);

    std::vector<AStarNode *>::iterator findNodeWithLeastFScore(std::vector<AStarNode *> vector);

    bool safe(xy pair);

    AStarNode *findNodeInOpen(std::vector<AStarNode *> vector, std::pair<int, int> pair);

    uint64_t manhattan(xy src, xy dest);
};

#endif //AVACADOS_A_H
