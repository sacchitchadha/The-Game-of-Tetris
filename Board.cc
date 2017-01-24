#include "Board.h"
#include "Coords.h"
#include <vector>
#include "Cell.h"
#include "Block.h"
#include "TextView.h"
#include "GraphicView.h"
#include "View.h"
#include <iostream>

using namespace std;


Board::Board(int numRows, int numCols, Coords startCoords, vector<View*> v): 
numRows{numRows}, numCols{numCols}, startCoords{startCoords}, displays{v},
totalRowsCleared{0} {
	for(int i = 0; i < numRows; ++i){
		vector<Cell> oneRow;
		for(int j = 0; j < numCols; ++j){
			oneRow.emplace_back(Cell{' '});
		}
		theBoard.emplace_back(oneRow);
	}
}

Board::~Board(){ 
	deleteAliveBlocks();
}

bool Board::isRowFilled(int rowNum) {
	for(int i = 0; i < numCols; ++i){
		if (theBoard[rowNum][i].isFree()) return false;
	}
	return true;
}

void Board::addToAliveBlocks(Block* b) { aliveBlocks.emplace_back(b); } 

Coords Board::getStartCoords() { return startCoords; } 

void Board::updateCell(int x, int y, char newChar) { 
	theBoard[x][y].setChar(newChar); 
	int len = displays.size();
	for(int i = 0; i < len; ++i){ displays[i]->notify(x, y, newChar);}
}

int Board::updateScore(int level) { 
	int numRowsCleared = 0;
	int scoreInc = 0;
	for(int i = 0; i < numRows; ++i){
		if(isRowFilled(i)){
			for(int j = 0; j < numCols; ++j){
				clearCell(i, j);
			}
			++numRowsCleared;
		}
	}
	totalRowsCleared += numRowsCleared;
	if(numRowsCleared > 0) scoreInc += (level+numRowsCleared)*(level+numRowsCleared);
	// removing dead blocks here
	int i = 0;
	while(i < aliveBlocks.size()){
		if(aliveBlocks[i]->numCoordsOccupied() == 0){
			delete aliveBlocks[i];
			int lvl = aliveBlocks[i]->getBlockLevel();
			scoreInc += (lvl+1)*(lvl+1);
			aliveBlocks.erase(aliveBlocks.begin() + i);
		}else{ ++i; }
	}
	return scoreInc;

}

void Board::clearCell(int x, int y) { 
// copy cols down and remove coords from alive blocks
	for(int i = x; i > 0; --i){
		updateCell(i, y, theBoard[i-1][y].getChar());
	}

	for(int i =0; i < aliveBlocks.size(); ++i){
		aliveBlocks[i]->removeCoord(Coords {x, y});
	}	
}

void Board::clearBoard(){ 
	deleteAliveBlocks();
	int len = aliveBlocks.size();
	for(int i = 0; i < len; ++i){
		delete aliveBlocks[i];
	}
	for(int i = 0; i < numRows; ++i){
		for(int j = 0; j < numCols; ++j){
			updateCell(i, j, ' ');
		}
	}
} 

void Board::deleteAliveBlocks(){ 
	int len = aliveBlocks.size();
	for(int i = 0; i < len; ++i){
		delete aliveBlocks[i];
	}
	aliveBlocks.clear();
}

bool Board::isFree(Coords c){
	int x = c.getX();
	int y = c.getY();
	if(x < 0 || x >= numRows) return false;
	if(y < 0 || y >= numCols) return false;
	return theBoard[x][y].isFree();
}

int Board::getTotalRowsCleared(){ return totalRowsCleared; } 

void Board::addView(View* v){displays.emplace_back(v);} 






















