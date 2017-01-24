#include "Block.h"
#include "TBlock.h"
#include "Coords.h"
#include "Board.h"
#include <vector>
#include <stdexcept>

using namespace std;

TBlock::TBlock(Board* b, int level):Block{b, level}{
	blockType = 'T';
	int startX = theBoard->getStartCoords().getX();
	int startY = theBoard->getStartCoords().getY();
	theCoords.emplace_back(Coords{startX, startY});
	theCoords.emplace_back(Coords{startX, startY+1});
	theCoords.emplace_back(Coords{startX, startY+2});
	theCoords.emplace_back(Coords{startX+1, startY+1});

	if(!isCoordsFreeOnBoard()) throw out_of_range("T");

	updateBoard();
}


void TBlock::clockwise(){
	// clear coords from board
	clearCoordsOnBoard();
	// if else statements to check which config it is
	if(presentConfig==1){
		presentConfig=2;
		// make clockwise changes
		theCoords[0].setX(theCoords[0].getX()-1);
		theCoords[0].setY(theCoords[0].getY()+1);
		theCoords[1].setY(theCoords[1].getY()-1);
		theCoords[2].setY(theCoords[2].getY()-1);
	}else if(presentConfig==2){
		presentConfig=3;
		// make clockwise changes
		theCoords[0].setX(theCoords[0].getX()+1);
		theCoords[1].setX(theCoords[1].getX()+1);
		theCoords[2].setX(theCoords[2].getX()+1);
		theCoords[3].setY(theCoords[3].getY()+1);
	}else if(presentConfig==3){
		presentConfig=4;
		// make clockwise changes
		theCoords[0].setX(theCoords[0].getX()-1);
		theCoords[0].setY(theCoords[0].getY()-1);
		theCoords[1].setX(theCoords[1].getX()-1);
		theCoords[2].setX(theCoords[2].getX()-1);
		theCoords[3].setY(theCoords[3].getY()-2);
	}else{
		presentConfig=1;
		// make clockwise changes
		theCoords[0].setX(theCoords[0].getX()+1);
		theCoords[1].setY(theCoords[1].getY()+1);
		theCoords[2].setY(theCoords[2].getY()+1);
		theCoords[3].setY(theCoords[3].getY()+1);
	}
	// check if coords are free on board
	if(!isCoordsFreeOnBoard()){
		if(presentConfig==1){
			presentConfig=4;
			// make anticlockwise changes
			theCoords[0].setX(theCoords[0].getX()-1);
			theCoords[1].setY(theCoords[1].getY()-1);
			theCoords[2].setY(theCoords[2].getY()-1);
			theCoords[3].setY(theCoords[3].getY()-1);
		}else if(presentConfig==2){
			presentConfig=1;
			// make anticlockwise changes
			theCoords[0].setX(theCoords[0].getX()+1);
			theCoords[0].setY(theCoords[0].getY()-1);
			theCoords[1].setY(theCoords[1].getY()+1);
			theCoords[2].setY(theCoords[2].getY()+1);
		}else if(presentConfig==3){
			presentConfig=2;
			// make anticlockwise changes
			theCoords[0].setX(theCoords[0].getX()-1);
			theCoords[1].setX(theCoords[1].getX()-1);
			theCoords[2].setX(theCoords[2].getX()-1);
			theCoords[3].setY(theCoords[3].getY()-1);
		}else{
			presentConfig=3;
			// make anticlockwise changes
			theCoords[0].setX(theCoords[0].getX()+1);
			theCoords[0].setY(theCoords[0].getY()+1);
			theCoords[1].setX(theCoords[1].getX()+1);
			theCoords[2].setX(theCoords[2].getX()+1);
			theCoords[3].setY(theCoords[3].getY()+2);
		}
	}
	// finally update the board
	updateBoard();
}

void TBlock::anticlockwise(){
	// clear coords from board
	clearCoordsOnBoard();
	// if else statements to check which config it is
	if(presentConfig==1){
		presentConfig=4;
		// make anticlockwise changes
		theCoords[0].setX(theCoords[0].getX()-1);
		theCoords[1].setY(theCoords[1].getY()-1);
		theCoords[2].setY(theCoords[2].getY()-1);
		theCoords[3].setY(theCoords[3].getY()-1);
	}else if(presentConfig==2){
		presentConfig=1;
		// make anticlockwise changes
		theCoords[0].setX(theCoords[0].getX()+1);
		theCoords[0].setY(theCoords[0].getY()-1);
		theCoords[1].setY(theCoords[1].getY()+1);
		theCoords[2].setY(theCoords[2].getY()+1);
	}else if(presentConfig==3){
		presentConfig=2;
		// make anticlockwise changes
		theCoords[0].setX(theCoords[0].getX()-1);
		theCoords[1].setX(theCoords[1].getX()-1);
		theCoords[2].setX(theCoords[2].getX()-1);
		theCoords[3].setY(theCoords[3].getY()-1);
	}else{
		presentConfig=3;
		// make anticlockwise changes
		theCoords[0].setX(theCoords[0].getX()+1);
		theCoords[0].setY(theCoords[0].getY()+1);
		theCoords[1].setX(theCoords[1].getX()+1);
		theCoords[2].setX(theCoords[2].getX()+1);
		theCoords[3].setY(theCoords[3].getY()+2);
	}
	
	// check if coords are free on board
	if(!isCoordsFreeOnBoard()){
		if(presentConfig==1){
			presentConfig=2;
			// make clockwise changes
			theCoords[0].setX(theCoords[0].getX()-1);
			theCoords[0].setY(theCoords[0].getY()+1);
			theCoords[1].setY(theCoords[1].getY()-1);
			theCoords[2].setY(theCoords[2].getY()-1);
		}else if(presentConfig==2){
			presentConfig=3;
			// make clockwise changes
			theCoords[0].setX(theCoords[0].getX()+1);
			theCoords[1].setX(theCoords[1].getX()+1);
			theCoords[2].setX(theCoords[2].getX()+1);
			theCoords[3].setY(theCoords[3].getY()+1);
		}else if(presentConfig==3){
			presentConfig=4;
			// make clockwise changes
			theCoords[0].setX(theCoords[0].getX()-1);
			theCoords[0].setY(theCoords[0].getY()-1);
			theCoords[1].setX(theCoords[1].getX()-1);
			theCoords[2].setX(theCoords[2].getX()-1);
			theCoords[3].setY(theCoords[3].getY()-2);
		}else{
			presentConfig=1;
			// make clockwise changes
			theCoords[0].setX(theCoords[0].getX()+1);
			theCoords[1].setY(theCoords[1].getY()+1);
			theCoords[2].setY(theCoords[2].getY()+1);
			theCoords[3].setY(theCoords[3].getY()+1);
		}
	}
	// finally update the board
	updateBoard();
}















