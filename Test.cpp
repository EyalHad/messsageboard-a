#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


#include "Board.hpp"
#include "Direction.hpp"
#include "doctest.h"
using namespace ariel;

ariel::Board board;

TEST_CASE("Light Test (1) ")
{ 
    CHECK(board.read(1,1,Direction::Horizontal,3) == "___");
    CHECK(board.read(2,2,Direction::Horizontal,3) == "___");
    CHECK(board.read(3,3,Direction::Horizontal,3) == "___");
    CHECK(board.read(4,4,Direction::Horizontal,3) == "___");
    CHECK(board.read(5,5,Direction::Horizontal,3) == "___");
    CHECK(board.read(6,6,Direction::Horizontal,3) == "___");
}
TEST_CASE("Light Test (2) ")
{
    CHECK(board.read(1,2,Direction::Vertical,3) == "___");
    CHECK(board.read(2,3,Direction::Vertical,3) == "___");
    CHECK(board.read(3,4,Direction::Vertical,3) == "___");
    CHECK(board.read(4,5,Direction::Vertical,3) == "___");
    CHECK(board.read(5,6,Direction::Vertical,3) == "___");
    CHECK(board.read(6,7,Direction::Vertical,3) == "___");
}
TEST_CASE("Medium Test (3) ")
{
    board.post(1,1,Direction::Horizontal,"TEST_ONE");
    CHECK(board.read(1,1,Direction::Horizontal,8) == "TEST_ONE");
    board.post(1,1,Direction::Horizontal,"_____TWO");
    CHECK(board.read(1,1,Direction::Horizontal,8) == "TEST_TWO");
    board.post(1,1,Direction::Horizontal,"TEST_ONE_TWO");
    CHECK(board.read(1,1,Direction::Horizontal,12) == "TEST_ONE_TWO");
}
TEST_CASE("Medium Test (4) ")
{
    board.post(1,1,Direction::Horizontal,"TEST_ONE");
    CHECK(board.read(1,1,Direction::Vertical,8) == "T______");
    CHECK(board.read(1,2,Direction::Vertical,8) == "_E_____");
    CHECK(board.read(1,3,Direction::Vertical,8) == "__S____");
    CHECK(board.read(1,4,Direction::Vertical,8) == "___T____");
    board.post(1,1,Direction::Horizontal,"_____TWO");
    CHECK(board.read(1,1,Direction::Horizontal,8) == "TEST_TWO");
    board.post(1,2,Direction::Horizontal,"_EST_ONE_TWO");
    CHECK(board.read(2,2,Direction::Horizontal,12) == "TEST_ONE_TWO");
}



