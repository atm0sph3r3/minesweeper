#include <ctime>
#include <cstdlib>
#include "Tile.h"

Tile::Tile() : type(BLANK), numBombs(0){
    //ctor
}

Tile::~Tile(){
    //dtor
}

Tile::Tile(tileType type, int numBombs) : type(type), numBombs(numBombs){
    //no code
}
