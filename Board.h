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
        /**
         * Return vector of pointers to mine locations
         */
        std::vector<Tile*> getMineLocations() const { return mineLocations; }
        /**
         * Return gameBoard
         */
        std::vector<std::vector<Tile> > getGameboard() const { return gameBoard; }
        /*
         * Draw current state of board
         */
        void drawBoard() const;
    private:
        //Size of board (size x size). Currently fixed at 8x8
        int size;
        //Number of MINES on board. Currently fixed at 8
        int totalNumMines;
        //A 2D vector containing a collection of Tiles
        std::vector<std::vector<Tile> > gameBoard;
        //Vector of MINE locations
        std::vector<Tile*> mineLocations;
        /**
         * Set mines
         */
        void addMines();
        /**
         * Set numMines in NO_MINE Tiles
         */
        void setNumMines();
};

#endif // BOARD_H
