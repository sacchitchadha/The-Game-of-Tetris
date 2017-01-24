#ifndef __LEVEL4_H__
#define __LEVEL4_H__

#include "Level.h"
#include <string>

class Level4 : public Level{
public:
	Level4(std::string);
	char getCharForBlockType() override;
};
#endif

