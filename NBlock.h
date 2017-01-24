#ifndef __NBLOCK_H__
#define __CBLOCK_H__

#include "Block.h"
class Board;

class NBlock: public Block {
	void config1();
	void config2();
public:
	NBlock(Board*, int);
	void clockwise() override;
	void anticlockwise() override;
};

#endif

