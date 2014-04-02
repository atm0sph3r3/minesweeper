#include <ctime>
#include <cstdlib>
#include <vector>
#include <iostream>
#include "Board.h"
#include "Tile.h"

using namespace std;

//Temporarily set size and numMines
Board::Board() : size(8), totalNumMines(8){
    //allocate memory for enough rows
    gameBoard.resize(size);
}

Board::~Board(){
	//intentionally blank
}

void Board::initializeBoard(){
	//Initially set all Tiles as NO_MINE
    for(int i = 0; i < size; i++){
    	for(int j = 0; j < size; j++){
    		(gameBoard.at(i)).push_back(Tile(Tile::NO_MINE,0,i,j));
    	}
    }
    //Add mines to Board
    addMines();
    //Set numMines for NO_MINE Tiles
    setNumMines();
}

void Board::addMines(){
	int row,column;

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
    			pTile->setTileTypeTile(Tile::MINE);
    			mineLocations.push_back(pTile);
    			break;
    		}
    	}
    }
}

void Board::setNumMines(){
	int row,column;

	for(vector<Tile*>::const_iterator iter = mineLocations.begin(); iter != mineLocations.end(); iter++){
		row = (*iter)->getRow();
		column = (*iter)->getColumn();

		//Check Tiles above MINE
		if(row - 1 >= 0){
			//Tile immediately above
			gameBoard[row-1][column].addMine();
			//Tile in upper left corner
			if(column -1 >= 0){
				gameBoard[row-1][column-1].addMine();
			}
			//Tile in upper right corner
			if(column + 1 < size){
				gameBoard[row-1][column+1].addMine();
			}
		}
		//Check Tiles below MINE
		if(row + 1 < size){
			//Tile immediately above
			gameBoard[row+1][column].addMine();
			//Tile in lower left corner and immediate left
			if(column -1 >= 0){
				gameBoard[row+1][column-1].addMine();
				gameBoard[row][column-1].addMine();
			}
			//Tile in lower right corner and immediate right
			if(column + 1 < size){
				gameBoard[row+1][column+1].addMine();
				gameBoard[row][column+1].addMine();
			}
		}
	}
}

//Draws current status of Board
void Board::drawBoard()const{
	cout << "    ";
	//Draw key for columns
	for(int i = 0; i < size; i++){
		cout << " " << i << " ";
	}
	cout << endl;

	//Draw dashes under keys
	cout << "    ";
	for(int i = 0; i < size; i++){
		cout << " - ";
	}
	cout << endl;

	//Print out " O " for an UNPLAYED space, " X " for a PLAYED space
	for(int i = 0; i < size; i++){
		//Print key for rows
		cout << i << " | ";
		for(int j = 0; j < size; j++){
			if(gameBoard.at(i).at(j).isUnplayed()){
				cout << " O ";
			} else {
				cout << " X ";
			}
		}
		cout << endl;
	}
}

