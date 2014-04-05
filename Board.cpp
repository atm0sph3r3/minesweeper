#include <ctime>
#include <cstdlib>
#include <vector>
#include <iostream>
#include "Board.h"
#include "Tile.h"

using namespace std;

//Default ctor
Board::Board():size(0),totalNumMines(0),isDone(false), didWin(false){
	//no code
}

//Ctor accepting number ints for size of board, number of mines, and set isDone to false
Board::Board(int size, int numMines) : size(size), totalNumMines(numMines), isDone(false), didWin(false){
    //allocate memory for enough rows
    gameBoard.resize(size);
}

//Dtor
Board::~Board(){
	//intentionally blank
}

//Set up Board
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

//Add mines to Board
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

//Set numMines for Tiles of type NO_MINE
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
			}
			//Tile in lower right corner and immediate right
			if(column + 1 < size){
				gameBoard[row+1][column+1].addMine();
			}
		}
		if(column + 1 < size){
			gameBoard[row][column+1].addMine();
		}
		if(column - 1 >= 0){
			gameBoard[row][column-1].addMine();
		}
	}
}

//Draws current status of Board
void Board::drawBoard()const{
	Tile tile;

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

	//Print out "| |" for an UNPLAYED space, " X " for a PLAYED space
	for(int i = 0; i < size; i++){
		//Print key for rows
		cout << i << " | ";
		for(int j = 0; j < size; j++){
			tile = (gameBoard.at(i)).at(j);
			if(tile.getStatus() == Tile::UNPLAYED){
				cout << " X ";
			} else if(tile.getStatus() == Tile::PLAYED && tile.getTileType() != Tile::MINE){
				cout << " 0 ";
			} else if(tile.getStatus() == Tile::SHOW_NUM){
				cout << " " << tile.getNumMines() << " ";
			} else {
				cout << " M ";
			}
		}
		cout << endl;
	}
}

//Recursively check Tiles
void Board::revealTiles(int row, int column){
	//Be sure that a legitimate Tile is chosen
	if(row < size && column < size){
		//Tile must not be a mine. If so, game ends.
		if(gameBoard[row][column].getTileType() != Tile::MINE){
			//If Tile hasn't already been played either directly or indirectly
			if(gameBoard[row][column].getStatus() == Tile::UNPLAYED){
				//Tile has no mines surrounding it. Check Tiles surrounding it.
				//Else set it's status as SHOW_NUM so number of mines surrounding it will be displayed
				if(gameBoard[row][column].getNumMines() == 0){
					//Mark Tile as played
					gameBoard[row][column].setStatus(Tile::PLAYED);
					//Check Tiles above Tile played
					if(row - 1 >= 0){
						//Tile immediately above
						revealTiles(row-1,column);
						//Tile in upper left corner
						if(column -1 >= 0){
							revealTiles(row-1,column-1);
						}
						//Tile in upper right corner
						if(column + 1 < size){
							revealTiles(row-1,column+1);
						}
					} //if row above check
					//Check Tiles below MINE
					if(row + 1 < size){
						//Tile immediately above
						revealTiles(row+1,column);
						//Tile in lower left corner and immediate left
						if(column -1 >= 0){
							revealTiles(row+1,column-1);
						}
						//Tile in lower right corner and immediate right
						if(column + 1 < size){
							revealTiles(row+1,column+1);
						}
					} //if row below check

					//Tile immediately to the right of the chosen Tile
					if(column + 1 < size){
						revealTiles(row,column+1);
					}//if

					//Tile immediately to the left of the chosen Tile
					if(column - 1 >= 0){
						revealTiles(row,column-1);
					}//if
				} else {
					(gameBoard.at(row)).at(column).setStatus(Tile::SHOW_NUM);
				}
			}//if already played
		} else {
			(gameBoard.at(row)).at(column).setStatus(Tile::PLAYED);
			//Game over
			isDone = true;
		}
	}//if size check
}

//Print current status of game
void Board::printGameStatus() const {
	if(!isDone){
		cout << "Choose a tile ([row] [column]) based on the grid" << endl;
	} else {
		cout << "Game over. Try again." << endl;
	}
}

//Check whether there are any available moves left
void Board::checkEnd() {
	int movesLeft = 0;

	//Check the number of UNPLAYED Tiles remaining
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if(gameBoard.at(i).at(j).getStatus() == Tile::UNPLAYED){
				++movesLeft;
			}
		}
	}

	if(movesLeft == totalNumMines){
		isDone = true;
		didWin = true;
	}

}
