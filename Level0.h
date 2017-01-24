#ifndef __LEVEL0_H__
#define __LEVEL0_H__

#include "Level.h"
#include <string>

class Level0 : public Level
{
public:
	Level0(std::string);
	char getCharForBlockType() override;
};
#endif

