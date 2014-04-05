#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Tile.h"

class Board
{
    public:
		//Default ctor
		Board();
		//Ctor
        Board(int sizeOfBoard, int numberOfMines);
        //Dtor
        virtual ~Board();
        /*
         * @brief Public function to add Tiles and set their attributes
         */
        void initializeBoard();
        /*
         * @briefReturn vector of pointers to Tiles of type MINE
         */
        std::vector<Tile*> getMineLocations() const { return mineLocations; }
        /*
         * @brief Return reference to gameBoard
         */
        std::vector<std::vector<Tile> >& getGameboard() { return gameBoard; }
        /*
         * @brief Draw current state of board
         */
        void drawBoard() const;
        /*
         * @brief Return current game status
         */
        bool getGameStatus() const { return isDone; }
        /*
         * @brief Print directive to user, if applicable.
         */
        void printGameStatus() const;
        /**
         * @brief Recursively check Tile types
         * @param row user selected Tile row
         * @param column user selected Tile column
         */
        void revealTiles(int row, int column);

        /*
         * @brief Determine whether there are any available moves left
         *
         */
        void checkEnd();
        /*
         * @brief Return whether or not the user won
         */
        bool getDidWin() const { return didWin; }
    private:
        //Size of board (size x size)
        int size;
        //Number of MINES on board.
        int totalNumMines;
        //A 2D vector containing a collection of Tiles
        std::vector<std::vector<Tile> > gameBoard;
        //Vector of MINE locations
        std::vector<Tile*> mineLocations;
        /**
         * Add mines to the Board
         */
        void addMines();
        /**
         * Set the number of mines surrounding Tiles of type NO_MINE
         */
        void setNumMines();
        //Status of game. True = game over
        bool isDone;
        //Whether or not the user won
        bool didWin;
};

#endif // BOARD_H
