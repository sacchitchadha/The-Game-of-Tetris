#ifndef __LEVEL5_H__
#define __LEVEL5_H__

#include "Level.h"
#include <string>

class Level5 : public Level
{
public:
	Level5(std::string);
	char getCharForBlockType() override;
};
#endif

