#ifndef __LEVEL2_H__
#define __LEVEL2_H__

#include "Level.h"
#include <string>

class Level2 : public Level
{
public:
	Level2(std::string);
	char getCharForBlockType() override;
};
#endif

