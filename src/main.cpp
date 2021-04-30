#include <iostream>
#include "maze_graph.h"
#include "maze_parser.h"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "Usage:\n" << argv[0] << "<2D Map filepath>";
        return -1;
    }
    MazeParser parser(argv[1]);
    TraverseMaze m;
    m.find_shortest_path(parser.getRootNode(), parser.getNumOfAvacados());
    return 0;
}