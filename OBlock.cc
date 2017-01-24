#include "OBlock.h"
#include "Board.h"
#include "Block.h"
#include "Coords.h"
#include <vector>
#include <stdexcept>

using namespace std;

OBlock::OBlock(Board* b, int level):Block{b, level}{
	blockType = 'O';
	Coords sc = theBoard->getStartCoords();
	theCoords.emplace_back(Coords{sc.getX(), sc.getY()});
	theCoords.emplace_back(Coords{sc.getX(), sc.getY()+1});
	theCoords.emplace_back(Coords{sc.getX()+1, sc.getY()});
	theCoords.emplace_back(Coords{sc.getX()+1, sc.getY()+1});

	if(!isCoordsFreeOnBoard()) throw out_of_range("O");

	updateBoard();
}

void OBlock::clockwise(){
	if(level == 3 || level == 4) moveDown();
}

void OBlock::anticlockwise(){
	if(level == 3 || level == 4) moveDown();
}


