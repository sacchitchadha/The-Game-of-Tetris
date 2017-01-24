#include "Level1.h"
#include <cstdlib>

using namespace std;

Level1::Level1(string fileName) : Level{1, fileName} {}

char Level1::getCharForBlockType()
{
	if(!isRandom()){
		return readFromFile();
	}
	
	int random = rand() % 12;

	if (random == 0)
	{
		return 'S';
	}
	else if (random == 1)
	{
		return 'Z';
	}
	else if (random == 2 || random == 3)
	{
		return 'O';
	}
	else if (random == 4 || random == 5)
	{
		return 'T';
	}
	else if (random == 6 || random == 7)
	{
		return 'I';
	}
	else if (random == 8 || random == 9)
	{
		return 'T';
	}
	else if (random == 10 || random == 11)
	{
		return 'I';
	}
	// control never reaches here
	return 'Q';
}

