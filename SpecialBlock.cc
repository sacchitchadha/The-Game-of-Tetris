#include "Block.h"
#include "SpecialBlock.h"
#include "Coords.h"
#include "Board.h"
#include <stdexcept>
#include <vector>

using namespace std;

SpecialBlock::SpecialBlock(Board *b,int level) : Block{b, level} {
	blockType = '*';
	theCoords.emplace_back(Coords{3, 5});

	if(!isCoordsFreeOnBoard()) throw out_of_range{"*"};

	updateBoard();
}


void SpecialBlock::clockwise() {}


void SpecialBlock::anticlockwise() {}

