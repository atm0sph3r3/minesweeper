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
        enum tileType {NO_MINE, MINE, USED};
        /**
         * Default constructor
         */
        Tile();
        /**
         * Constructor
         * @param tileType
         * @param numBombs
         */
        Tile(tileType type, int numBombs = 0);
        /**
         * Destructor
         */
        virtual ~Tile();
        /**
         * Return Tile type
         * @return type
         */
        tileType getTileType() { return type; }
        /**
         * Sets a type for Tile
         * @param tileType
         */
        void setTileTypeTile(tileType type) { this->type = type; }
        /**
         * Returns the number of MINEs surrounding a Tile
         * @return numMines
         */
        int getNumMines() { return numMines; }
        /**
         * Add number of mines to a Tile
         * Pre-condition: Tile is NO_MINE and number is positive
         * Post-condition: Changed number of mines associated with
         * a Tile
         */
        void addMines(int number);
        /**
         * Check whether a Tile is of type MINE
         */
        bool isMine();
    private:
        //Type of Tile using enum tileType
        tileType type;
        //Number of mines surrounding a NO_MINE tile
        int numMines;

};

#endif // TILE_H
