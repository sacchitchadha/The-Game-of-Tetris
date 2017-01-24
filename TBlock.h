#ifndef TBLOCK_H
#define TBLOCK_H

#include "Block.h"
class Board;

class TBlock: public Block {
public:
	TBlock(Board*, int);
	void clockwise() override;
	void anticlockwise() override;
};

#endif

