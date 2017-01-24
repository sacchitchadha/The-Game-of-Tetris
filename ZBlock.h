#ifndef ZBLOCK_H
#define ZBLOCK_H

#include "Block.h"

class Board;

class ZBlock: public Block {
	void config1ToConfig2();
	void config2ToConfig1();
public:
	ZBlock(Board* b, int);
	void clockwise() override;
	void anticlockwise() override;
};

#endif

