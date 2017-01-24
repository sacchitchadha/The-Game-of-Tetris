#include "Level5.h"
#include <cstdlib>

using namespace std;

Level5::Level5(string fileName) : Level{5, fileName} {}


char Level5::getCharForBlockType()
{
	if(!isRandom()){
		return readFromFile();
	}
	
	int random = rand() % 14;

	if (random == 0)
	{
		return 'S';
	}
	else if (random == 1)
	{
		return 'Z';
	}
	else if (random == 2 || random == 3 || random == 4)
	{
		return 'N';
	}
	else if (random == 5 || random == 6 || random == 7)
	{
		return 'C';
	}
	else if (random == 8 || random == 9)
	{
		return 'I';
	}
	else if (random == 10)
	{
		return 'T';
	}
	else if (random == 11)
	{
		return 'L';
	}
	else if (random == 12)
	{
		return 'J';
	}
	else{
		return '*';
	}
	// control never reaches here
	return 'Q';
}

