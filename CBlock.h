#ifndef __CBLOCK_H__
#define __CBLOCK_H__

#include "Block.h"
class Board;

class CBlock: public Block {
public:
	CBlock(Board*, int);
	void clockwise() override;
	void anticlockwise() override;
};

#endif

