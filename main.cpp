#include <iostream>
#include "Board.h"

using namespace std;

int main(){
	int column, row;

    Board newBoard;
    newBoard.initializeBoard();
    newBoard.drawBoard();
    while(!newBoard.getGameStatus()){
    	newBoard.printGameStatus();
    	cin >> row >> column;
    	newBoard.revealTiles(newBoard.getGameboard().at(row).at(column));
    	newBoard.drawBoard();
    }
    return 0;
}
