#include <ctime>
#include <cstdlib>
#include <vector>
#include <iostream>
#include "Board.h"
#include "Tile.h"

using namespace std;

Board::Board() : size(8), totalNumMines(8){
    //allocate memory for enough rows
    gameBoard.resize(size);
}

Board::~Board(){
	//intentionally blank
}

void Board::initializeBoard(){
	int column,row;

	//Initially set all Tiles as NO_MINE
    for(int i = 0; i < size; i++){
    	for(int j = 0; j < size; j++){
    		(gameBoard.at(i)).push_back(Tile(Tile::NO_MINE,0));
    	}
    }
    //Seed PRN generator with current time
    srand(time(NULL));

    //Randomly generate totalNumMines and add them to gameBoard
    for(int i = 0; i < totalNumMines; i++){
    	bool hasTile = false;
    	while(true){
    		//Generate a random row and column
    		row = rand() % size;
    		column = rand() % size;
    		//Get pointer to Tile at row and column
    		Tile* pTile = &((gameBoard.at(row)).at(column));
    		for(vector<Tile*>::const_iterator iter = mineLocations.begin(); iter != mineLocations.end(); iter++){
    			if((*iter) == pTile){
    				hasTile = true;
    				break;
    			} else {
    				hasTile = false;
    			}
    		}
    		//If MINE Tile isn't already in mineLocations vector, add it
    		if(!hasTile){
    			mineLocations.push_back(pTile);
    			break;
    		}
    	}
    }
}
