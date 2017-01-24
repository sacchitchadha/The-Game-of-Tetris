#ifndef __LEVEL3_H__
#define __LEVEL3_H__

#include "Level.h"
#include <string>

class Level3 : public Level
{
public:
	Level3(std::string);
	char getCharForBlockType() override;
};
#endif

