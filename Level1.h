#ifndef __LEVEL1_H__
#define __LEVEL1_H__

#include "Level.h"
#include <string>

class Level1 : public Level
{
public:
	Level1(std::string);
	char getCharForBlockType() override;
};
#endif

