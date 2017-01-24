#ifndef BLOCK_H
#define BLOCK_H

#include "Coords.h"
#include <vector>

class Board;

class Block {
private:
	bool isLeftFree();
	bool isRightFree();
	bool isDownFree();
protected:
	int presentConfig;
	std::vector<Coords> theCoords;
	char blockType;
	Board* theBoard;
	int level;
	void updateBoard();
	bool isCoordsFreeOnBoard();
	void clearCoordsOnBoard();
public:
	Block(Board*, int); // for theBoard and levelCiB(iF) 
	virtual ~Block();
	void moveLeft();
	void moveRight();
	void moveDown();
	virtual void clockwise() = 0;
	virtual void anticlockwise() = 0;
	void drop();
	char getBlockType();
	void removeCoord(Coords);
	int numCoordsOccupied();
	int getBlockLevel();
	void removeItFromBoard();
};

#endif

