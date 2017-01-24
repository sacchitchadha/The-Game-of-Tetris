#ifndef __IBLOCK_H__
#define __IBLOCK_H__

#include "Block.h"
class Board;

class IBlock : public Block {
private:
	void config1ToConfig2();
	void config2ToConfig1();
public:
	IBlock(Board *, int);
	void clockwise() override;
	void anticlockwise() override;
};
#endif 

