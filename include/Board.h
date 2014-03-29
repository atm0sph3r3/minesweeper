#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Tile.h"

class Board
{
    public:
        Board(int size);
        virtual ~Board();
        void initializeBoard();
    protected:
    private:
        int size;
        std::vector<std::vector<Tile> > gameBoard;

};

#endif // BOARD_H
