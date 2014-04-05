#include <iostream>
#include "Board.h"

using namespace std;

int main(){
	//User entered row and column vars
	int column, row;
	//Create Board object, initialize its Tiles, and present it to the user
    Board newBoard(8,8);
    newBoard.initializeBoard();
    newBoard.drawBoard();

    //While game status is not done continue to accept user input
    while(!newBoard.getGameStatus()){
    	//Prompt user to enter row and column or show end
    	newBoard.printGameStatus();
    	cin >> row >> column;
    	//Check tiles and draw board based on move
    	newBoard.revealTiles(row,column);
    	newBoard.drawBoard();
    }
    //Tell user how they did
    if(!newBoard.getDidWin()){
    	cout << "Game over. Try again." << endl;
    } else {
    	cout << "You won! Why not make it more difficult?" << endl;
    }
    return 0;
}
