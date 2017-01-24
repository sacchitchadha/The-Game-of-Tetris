#ifndef OBLOCK_H
#define OBLOCK_H

#include "Block.h"

class Board;

class OBlock: public Block {
public:
	OBlock(Board*, int);
	void clockwise() override;
	void anticlockwise() override;
};

#endif

