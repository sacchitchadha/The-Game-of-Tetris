#include "Block.h"
#include "ZBlock.h"
#include "Coords.h"
#include "Board.h"
#include <vector>
#include <stdexcept>

using namespace std;

ZBlock::ZBlock(Board* b, int level):Block{b, level}{
	blockType = 'Z';
	int startX = theBoard->getStartCoords().getX();
	int startY = theBoard->getStartCoords().getY();
	theCoords.emplace_back(Coords{startX, startY});
	theCoords.emplace_back(Coords{startX, startY+1});
	theCoords.emplace_back(Coords{startX+1, startY+1});
	theCoords.emplace_back(Coords{startX+1, startY+2});

	if(!isCoordsFreeOnBoard()) throw out_of_range("Z");

	updateBoard();
}

void ZBlock::config1ToConfig2(){
	presentConfig = 1;
	theCoords[0].setX(theCoords[0].getX()+1);
	theCoords[0].setY(theCoords[0].getY()-2);
	theCoords[2].setX(theCoords[2].getX()+1);
	theCoords[2].setY(theCoords[2].getY()-1);
	theCoords[3].setY(theCoords[3].getY()+1);
}

void ZBlock::config2ToConfig1(){
	presentConfig = 2;
	theCoords[0].setX(theCoords[0].getX()-1);
	theCoords[0].setY(theCoords[0].getY()+2);
	theCoords[2].setX(theCoords[2].getX()-1);
	theCoords[2].setY(theCoords[2].getY()+1);
	theCoords[3].setY(theCoords[2].getY()-1);
}

void ZBlock::clockwise(){
	clearCoordsOnBoard();

	if(presentConfig==1) {config2ToConfig1();}
	else {config1ToConfig2();}

	if(!isCoordsFreeOnBoard()){
		if(presentConfig==1){config2ToConfig1();}
		else{config1ToConfig2();}
	}

	updateBoard();
}

void ZBlock::anticlockwise(){
	clockwise();
}

