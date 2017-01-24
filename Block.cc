#include "Block.h"
#include "Board.h"
#include "Coords.h"
#include <vector>
#include <iostream>

using namespace std;

Block::Block(Board* b, int level):theBoard{b}, level{level},
presentConfig{1} {}

Block::~Block() {}

void Block::updateBoard(){ // update cells on the board and notify dispalys
	for(int i = 0; i < theCoords.size(); ++i){
		theBoard->updateCell(theCoords[i].getX(),theCoords[i].getY(), blockType);
	}
}


void Block::moveLeft(){
	int len = theCoords.size();
	// clear its present position from the board
	clearCoordsOnBoard();

	if(isLeftFree()){
		// move it left
		for(int i = 0; i < len; ++i){
			theCoords[i].decY();
		}
	}
	updateBoard();
}

void Block::moveRight(){
	int len = theCoords.size();
	// clear its present position from the board
	clearCoordsOnBoard();
	if(isRightFree()){
		// move it right
		for(int i = 0; i < len; ++i){
			theCoords[i].incY();
		}
	}
	updateBoard();	
}

void Block::moveDown(){
	int len = theCoords.size();
	// clear its present position from the board
	clearCoordsOnBoard();
	if(isDownFree()){
		// move it left
		for(int i = 0; i < len; ++i){
			theCoords[i].incX();
		}
	}
	updateBoard();
}

void Block::drop(){
	clearCoordsOnBoard();
	while(true){
		if(!isDownFree()) break;
		for(int i = 0; i < theCoords.size(); ++i){
			theCoords[i].incX();
		}
	}
	updateBoard();
	theBoard->addToAliveBlocks(this);
}


char Block::getBlockType() { return blockType; }

// methods to check whether cells at specific coordinates on board are 
// free or not
bool Block::isLeftFree(){
	int len = theCoords.size();
	for(int i = 0; i < len; ++i){
		Coords c {theCoords[i].getX(), theCoords[i].getY()-1};
		if(!(theBoard->isFree(c))) return false;
	}
	return true;
}

bool Block::isRightFree(){
	int len = theCoords.size();
	for(int i = 0; i < len; ++i){
		Coords c {theCoords[i].getX(), theCoords[i].getY()+1};
		if(!(theBoard->isFree(c))) return false;
	}
	return true;
}

bool Block::isDownFree(){
	int len = theCoords.size();
	for(int i = 0; i < len; ++i){
		Coords c {theCoords[i].getX()+1, theCoords[i].getY()};
		if(!(theBoard->isFree(c))) return false;
	}
	return true;
}

// remove old coordinates of the block from the vector
void Block::removeCoord(Coords toRemove) {
	for(int i = 0; i < theCoords.size(); ++i){
		if(toRemove == theCoords[i]){
			theCoords.erase(theCoords.begin() + i);
			break;
		}
	}
}

int Block::numCoordsOccupied() { return theCoords.size(); }

bool Block::isCoordsFreeOnBoard() { 
	int len = theCoords.size();
	for(int i = 0; i < len; ++i){
		if(!theBoard->isFree(theCoords[i])) return false;
	}
	return true;
}

void Block::clearCoordsOnBoard(){
	int len = theCoords.size();
	for(int i = 0; i < len; ++i){
		theBoard->updateCell(theCoords[i].getX(), theCoords[i].getY(), ' ');
	}
}

int Block::getBlockLevel(){ return level; }

void Block::removeItFromBoard(){ clearCoordsOnBoard(); }



