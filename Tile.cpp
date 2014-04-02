#include <ctime>
#include <cstdlib>
#include "Tile.h"

/**
 *Additional constructor accepting number of mines surrounding a
 *tile as well as the Tile type.
*/
Tile::Tile():type(NO_MINE), numMines(0), row(0), column(0){
    //intentionally blank
}
//Destructor
Tile::~Tile(){
    //intentionally blank
}

Tile::Tile(tileType type, int numMines, int row, int column) : type(type), numMines(numMines), row(row), column(column), status(UNPLAYED){
    //intentionally blank
}

//Add mines to a Tile
void Tile::addMine(){
	if(this->type == NO_MINE){
		this->numMines += 1;
	}
}

//Returns true if Tile is of type MINE
bool Tile::isMine() const {
	if(type == MINE){
		return true;
	}
	return false;
}

//Returns true if Tile is type DONE
bool Tile::isUnplayed() const{
	if(status == UNPLAYED){
		return true;
	}
	return false;
}
