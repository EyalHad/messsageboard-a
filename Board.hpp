#ifndef  _BOARD
#define _BOARD



#include <iostream>
#include <string>
#include <math.h>
#include <vector>
using namespace std;
#include "Direction.hpp"
using ariel::Direction;

namespace ariel {

    class Board
    {
    private:
        // 4 Integers for a reasonable show -> so we will not print unneeded lines.
        unsigned _MinR = UINT32_MAX;
        unsigned _MinC = UINT32_MAX;
        unsigned _MaxR = 0;
        unsigned _MaxC = 0;

    public:
        Board(/* args */){}
        void post(unsigned int row, unsigned int column, Direction,const string &input);
        static std::string read(unsigned  int row, unsigned int column, Direction, unsigned int length);
        void show();
    };
}
#endif // ! _BOARD