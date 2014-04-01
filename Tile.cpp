#include <ctime>
#include <cstdlib>
#include "Tile.h"

/**
 *Additional constructor accepting number of mines surrounding a
 *tile as well as the Tile type.
*/
Tile::Tile() : type(NO_MINE), numMines(0){
    //intentionally blank
}
//Destructor
Tile::~Tile(){
    //intentionally blank
}

Tile::Tile(tileType type, int numMines) : type(type), numMines(numMines){
    //intentionally blank
}

//Add mines to a Tile
void Tile::addMines(int number){
	if(this->type == NO_MINE && number > 0){
		this->numMines += number;
	}
}

//Returns true if Tile is of type MINE
bool Tile::isMine(){
	if(type == MINE){
		return true;
	}
	return false;
}
