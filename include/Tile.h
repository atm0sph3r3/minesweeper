#ifndef TILE_H
#define TILE_H
/**
* Tile class describes a Minesweeper tile on the game board.
* A tile can be described as a bomb, blank, number of bombs surrounding
* it, or it can be used.
**/

class Tile {
    public:
        //Possible tile types
        enum tileType {BLANK, MINE, NUMBER, DONE};
        //Default ctor
        Tile();
        //Addt ctor
        Tile(tileType type, int numBombs = 0);
        //Dtor
        virtual ~Tile();
        //Return tile types
        tileType getTileType() { return type; }
        //Set tile type
        void setTileTypeTile(Tile::tileType type) { this->type = type; }
        //Return number of bombs surrounding a tile
        int getNumBombs() { return numBombs; }
    protected:
    private:
        tileType type;
        int numBombs;

};

#endif // TILE_H
