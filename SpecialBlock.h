#ifndef __SPECIALBLOCK_H__
#define __SPECIALBLOCK_H__

#include "Block.h"
class Board;

class SpecialBlock: public Block {
public:
	SpecialBlock(Board*, int);
	void clockwise() override;
	void anticlockwise() override;
};

#endif

