//
// Created by Dhara Balaji on 5/1/21.
//

#include <gtest/gtest.h>
#include "A*.h"
#include "maze_parser.h"

class TestAstar : public testing::Test
{
public:
    TestAstar() : testParser(MazeParser("data/test2.txt")) {}

    MazeParser testParser;
};

TEST_F(TestAstar, testDistance)
{
    auto grid = testParser.getGrid();
    auto rows = testParser.getRows();
    auto cols = testParser.getCols();

    auto astar = Astar(grid, rows, cols);

    auto d1 = astar.findPath(std::make_pair(2,2), std::make_pair(1,12));
    EXPECT_EQ(d1, 11);

    auto d2 = astar.findPath(std::make_pair(1,6), std::make_pair(6,14));
    EXPECT_EQ(d2, 17);
}