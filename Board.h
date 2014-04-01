#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Tile.h"

class Board
{
    public:
		/**
		 * Constructor.
		 * @param size size of board
		 */
        Board();
        /**
         * Destructor
         */
        virtual ~Board();
        /**
         * Add Tiles to board and set tileType
         */
        void initializeBoard();
        std::vector<Tile*> getMineLocations() { return mineLocations; }
    protected:
    private:
        //Size of board (size x size). Currently fixed at 8x8
        int size;
        //Number of MINES on board. Currently fixed at 8
        int totalNumMines;
        //A 2D vector containing a collection of Tiles
        std::vector<std::vector<Tile> > gameBoard;
        //Vector of MINE locations
        std::vector<Tile*> mineLocations;
};

#endif // BOARD_H
