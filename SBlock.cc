#include "Block.h"
#include "SBlock.h"
#include "Coords.h"
#include "Board.h"
#include <vector>
#include <stdexcept>

using namespace std;

SBlock::SBlock(Board* b, int level):Block{b, level}{
	blockType = 'S';
	int startX = theBoard->getStartCoords().getX();
	int startY = theBoard->getStartCoords().getY();
	theCoords.emplace_back(Coords{startX, startY+1});
	theCoords.emplace_back(Coords{startX, startY+2});
	theCoords.emplace_back(Coords{startX+1, startY});
	theCoords.emplace_back(Coords{startX+1, startY+1});

	if(!isCoordsFreeOnBoard()) throw out_of_range("S");

	updateBoard();
}

void SBlock::config1ToConfig2(){
	presentConfig = 1;
	theCoords[0].setX(theCoords[0].getX()+1);
	theCoords[0].setY(theCoords[0].getY()+1);
	theCoords[1].setY(theCoords[1].getY()+2);
	theCoords[2].setX(theCoords[2].getX()+1);
	theCoords[2].setY(theCoords[2].getY()-1);
}

void SBlock::config2ToConfig1(){
	presentConfig = 2;
	theCoords[0].setX(theCoords[0].getX()-1);
	theCoords[0].setY(theCoords[0].getY()-1);
	theCoords[1].setY(theCoords[1].getY()-2);
	theCoords[2].setX(theCoords[2].getX()-1);
	theCoords[2].setY(theCoords[2].getY()+1);
}

void SBlock::clockwise(){
	clearCoordsOnBoard();

	if(presentConfig==1) {config2ToConfig1();}
	else {config1ToConfig2();}

	if(!isCoordsFreeOnBoard()){
		if(presentConfig==1){config2ToConfig1();}
		else{config1ToConfig2();}
	}

	updateBoard();
}

void SBlock::anticlockwise(){
	clockwise();
}












