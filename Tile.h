#ifndef TILE_H
#define TILE_H
/**
* Tile class describes a Minesweeper tile on the game board.
* A tile can be described as a mine, not being a mine, or
* it has been used.
**/

class Tile {
    public:
        /*
         * @brief Enum describing types of Tiles
         */
        enum tileType {NO_MINE, MINE};
        /**
         * @brief Enum describing status of Tile
         */
        enum tileStatus{UNPLAYED,PLAYED, SHOW_NUM};
        /*
         * @brief Default ctor
         */
        Tile();
        /*
         * @brief Optional ctor
         * @param tileType
         * @param numBombs
         */
        Tile(tileType type, int numBombs = 0, int row=0, int column=0);
        /*
         * @brief Destructor
         */
        virtual ~Tile();
        /*
         * @brief Return Tile type
         * @return type
         */
        tileType getTileType() const { return type; }
        /*
         * @brief Sets a type for Tile
         * @param tileType
         */
        void setTileTypeTile(tileType type) { this->type = type; }
        /*
         * @brief Returns the number of MINEs surrounding a Tile
         * @return numMines
         */
        int getNumMines() const { return numMines; }
        /*
         * @brief Add number of mines to a Tile
         * Pre-condition: Tile is NO_MINE and number is positive
         * Post-condition: Changed number of mines associated with
         * a Tile
         */
        void addMine();
        /*
         * @brief Check whether a Tile is of type MINE
         */
        bool isMine() const;
        /*
         * @brief Return row number
         */
        int getRow() const { return row; }
        /*
         * @brief Return column number
         */
        int getColumn() const { return column; }
        /*
         * @brief Set the status of the Tile
         */
        void setStatus(tileStatus status);
        /*
         * @brief Get the status of the tile
         */
        tileStatus getStatus() const { return status; }
    private:
        //Type of Tile using enum tileType
        tileType type;
        //Number of mines surrounding a NO_MINE tile
        int numMines;
        //Row number
        int row;
        //Column number
        int column;
        //Tile status
        tileStatus status;

};

#endif // TILE_H
