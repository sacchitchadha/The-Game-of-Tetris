#include "Block.h"
#include "NBlock.h"
#include "Coords.h"
#include "Board.h"
#include <stdexcept>
#include <vector>

using namespace std;

NBlock::NBlock(Board *b,int level) : Block{b, level} {
	blockType = 'N';
	int startX = theBoard->getStartCoords().getX();
	int startY = theBoard->getStartCoords().getY();
	// setting its coords with respect to the boards starting coords
	theCoords.emplace_back(Coords{startX, startY+3});
	theCoords.emplace_back(Coords{startX+1, startY+2}); 
	theCoords.emplace_back(Coords{startX+2, startY+1}); 
	theCoords.emplace_back(Coords{startX+3, startY}); 
	if(!isCoordsFreeOnBoard()) throw out_of_range{"N"};

	// updating the board of its final coords
	updateBoard();
}

void NBlock::config1(){
	presentConfig = 1;
	theCoords[0].setY(theCoords[0].getY()+3);
	theCoords[1].setY(theCoords[1].getY()+1);
	theCoords[2].setY(theCoords[2].getY()-1);
	theCoords[3].setY(theCoords[3].getY()-3);
}

void NBlock::config2(){
	presentConfig = 2;
	theCoords[0].setY(theCoords[0].getY()-3);
	theCoords[1].setY(theCoords[1].getY()-1);
	theCoords[2].setY(theCoords[2].getY()+1);
	theCoords[3].setY(theCoords[3].getY()+3);
}

void NBlock::clockwise() {
	clearCoordsOnBoard();
	// rotate
	if(presentConfig == 1){ config2(); }
	else{ config1(); }
	// if rotated pos is filled, reverse the rotation
	if(!isCoordsFreeOnBoard()){
		if(presentConfig==1){config2();}
		else{config1();}
	}
	updateBoard();

}

void NBlock::anticlockwise() { clockwise(); }

