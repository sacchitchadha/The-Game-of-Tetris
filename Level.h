#ifndef __LEVEL_H__
#define __LEVEL_H__

#include <fstream>
#include <string>

class Level
{	
	std::ifstream file;
	std::string fileName;
	int level;
	bool random;
protected:
	char readFromFile();
public:
	Level(int, std::string);
	virtual ~Level();
	virtual char getCharForBlockType() = 0;
	int getLevel();
	bool isRandom();
	void setRandom();
	void setFile(std::string);
	void removeRandom();
};
#endif

