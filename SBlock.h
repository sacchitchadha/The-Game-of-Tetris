#ifndef SBLOCK_H
#define SBLOCK_H

#include "Block.h"

class Board;

class SBlock: public Block {
	void config1ToConfig2();
	void config2ToConfig1();
public:
	SBlock(Board* b, int);
	void clockwise() override;
	void anticlockwise() override;
};

#endif

