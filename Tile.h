#ifndef TILE_H
#define TILE_H
/**
* Tile class describes a Minesweeper tile on the game board.
* A tile can be described as a mine, not being a mine, or
* it has been used.
**/

class Tile {
    public:
        /**
         * Enum describing types of Tiles
         */
        enum tileType {NO_MINE, MINE};
        /**
         * Enum describing status of Tile
         */
        enum tileStatus{UNPLAYED,PLAYED, SHOW_NUM};
        /**
         * Default constructor
         */
        Tile();
        /**
         * Constructor
         * @param tileType
         * @param numBombs
         */
        Tile(tileType type, int numBombs = 0, int row=0, int column=0);
        /**
         * Destructor
         */
        virtual ~Tile();
        /**
         * Return Tile type
         * @return type
         */
        tileType getTileType() const { return type; }
        /**
         * Sets a type for Tile
         * @param tileType
         */
        void setTileTypeTile(tileType type) { this->type = type; }
        /**
         * Returns the number of MINEs surrounding a Tile
         * @return numMines
         */
        int getNumMines() const { return numMines; }
        /**
         * Add number of mines to a Tile
         * Pre-condition: Tile is NO_MINE and number is positive
         * Post-condition: Changed number of mines associated with
         * a Tile
         */
        void addMine();
        /**
         * Check whether a Tile is of type MINE
         */
        bool isMine() const;
        /**
         * Return row number
         */
        int getRow() const { return row; }
        /**
         * Return column number
         */
        int getColumn() const { return column; }
        /**
         * Set the status of the Tile
         */
        void setStatus(tileStatus status);
        /*
         * Get the status of the tile
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
