#include <ctime>
#include <cstdlib>
#include <vector>
#include "Board.h"
#include "Tile.h"

using namespace std;

Board::Board(int size) : size(size){
    //allocate memory for enough rows
    gameBoard.resize(size);
}

Board::~Board()
{
    //dtor
}

void Board::initializeBoard(){
    srand(time(NULL));
    int rndNum = rand() % 10;

    //Add Tiles to gameboard
    for(vector<vector<Tile> >::iterator iter = gameBoard.begin(); iter < gameBoard.end(); iter++){
        for(int i = 0; i < size; i++){
            //if newly generated number matches rndNum above, make it a mine
            //else leave it blank for now
            srand(time(NULL));
            if(rand() % 10 == rndNum){
                (*iter).push_back(Tile(Tile::MINE));
            } else {
                (*iter).push_back(Tile(Tile::BLANK));
            }
        }
    }
}
