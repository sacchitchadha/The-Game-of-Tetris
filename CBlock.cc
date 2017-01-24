#include "Block.h"
#include "CBlock.h"
#include "Coords.h"
#include "Board.h"
#include <stdexcept>
#include <vector>

using namespace std;

CBlock::CBlock(Board *b,int level) : Block{b, level} {
	blockType = 'C';
	int startX = theBoard->getStartCoords().getX();
	int startY = theBoard->getStartCoords().getY();
	// setting its coords with respect to the boards starting coords
	theCoords.emplace_back(Coords{startX, startY+1});
	theCoords.emplace_back(Coords{startX+1, startY}); 
	theCoords.emplace_back(Coords{startX+1, startY+1}); 
	theCoords.emplace_back(Coords{startX+1, startY+2});
	theCoords.emplace_back(Coords{startX+2, startY+1}); 
	if(!isCoordsFreeOnBoard()) throw out_of_range{"C"};
	// updating the board of its final coords
	updateBoard();
}

void CBlock::clockwise() {}

void CBlock::anticlockwise() {}

