#ifndef __JBLOCK_H__
#define __JBLOCK_H__

#include "Block.h"
class Board;

class JBlock: public Block {
private:
	void config1ToConfig2();
	void config2ToConfig3();
	void config3ToConfig4();
	void config4ToConfig1();
	void config1ToConfig4();
	void config2ToConfig1();
	void config3ToConfig2();
	void config4ToConfig3();
public:
	JBlock(Board*, int);
	void clockwise() override;
	void anticlockwise() override;
};
#endif

