#include "iblock.h"
#include "Board.h"
#include "Block.h"
#include "Coords.h"
#include <vector>
#include <stdexcept>
using namespace std;

IBlock::IBlock(Board *b, int level): Block{b, level}
{	
	blockType = 'I';
	Coords startCoords = theBoard->getStartCoords();
	for (int i = 0; i < 4; ++i)
	{
		theCoords.emplace_back(startCoords.getX() , startCoords.getY() + i);
	}
	if (!isCoordsFreeOnBoard())
	{
		throw out_of_range("I");
	}
	updateBoard();
}




void IBlock::config1ToConfig2(){
	presentConfig = 1;
	int len = theCoords.size();
	int tempX = theCoords[3].getX();
	for (int i = 0; i < len; ++i){ 
	// updating coordinates of block
		int tempY = theCoords[i].getY();
		theCoords[i].setX(tempX+3);
		theCoords[i].setY(tempY+i);
	}
} 

void IBlock::config2ToConfig1(){
	presentConfig = 2;
	int len = theCoords.size();
	int tempY = theCoords[0].getY();
	for (int i = 0; i < len; ++i){ 
		int tempX = theCoords[i].getX();
		theCoords[i].setX(tempX-i);
		theCoords[i].setY(tempY);
	}
}	

void IBlock::clockwise(){
	clearCoordsOnBoard();
	// rotate
	if(presentConfig == 1){ config2ToConfig1(); }
	else{ config1ToConfig2(); }

	if(!isCoordsFreeOnBoard()){
		if(presentConfig==1){config2ToConfig1();}
		else{config1ToConfig2();}
	}
	// finally update the board
	updateBoard();
}

void IBlock::anticlockwise() { clockwise(); }


