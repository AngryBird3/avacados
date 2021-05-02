#include <iostream>
#include "shortest_path.h"
#include "maze_parser.h"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "Usage:\n" << argv[0] << "<2D Map filepath> <bfs/astar>";
        return -1;
    }
    MazeParser parser(argv[1]);
    TraverseMaze *m;
    m = new DoBFS();
    std::cout << argv[2] << "\n";
    if (argc > 2 && strcmp(argv[2], "astar") == 0)
    {
        m = new DoAstar(parser.getGrid(), parser.getRows(), parser.getCols());
    }
    auto result = m->find_shortest_path(parser.getRootNode(), parser.getNumOfAvacados(), parser.getAvacadoNodes());
    std::cout << "total_moves= " << result.total_moves << "\n";
    for (auto r : result.moves_for_picking_avacados)
    {
        std::cout << r << "\n";
    }
    return 0;
}