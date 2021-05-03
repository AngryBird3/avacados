#include <iostream>
#include <fstream>
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
    if (argc > 2 && strcmp(argv[2], "astar") == 0)
    {
        m = new DoAstar(parser.getGrid(), parser.getRows(), parser.getCols());
    } else {
        m = new DoBFS();
    }
    auto result = m->find_shortest_path(parser.getRootNode(), parser.getNumOfAvacados(), parser.getAvacadoNodes());

//    // Print to std::out to
//    std::cout << "total_moves= " << result.total_moves << "\n";
//    for (const auto& r : result.moves_for_picking_avacados)
//    {
//        std::cout << r << "\n";
//    }

    std::ofstream out_f("test_output.txt");
    out_f << result.total_moves << "\n";
    for (auto r : result.moves_for_picking_avacados)
    {
        out_f << r << "\n";
    }
    return 0;
}