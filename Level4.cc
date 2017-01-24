#include "Level4.h"
#include "Level.h"
#include <cstdlib>

using namespace std;

Level4::Level4(string fileName) : Level{4, fileName}{}

char Level4::getCharForBlockType(){
	
	if(!isRandom()){
		return readFromFile();
	}	
	int random = rand() % 9;

	if (random == 0 || random == 1)
	{
		return 'S';
	}
	else if (random == 2 || random == 3)
	{
		return 'Z';
	}
	else if (random == 4)
	{
		return 'O';
	}
	else if (random == 5)
	{
		return 'T';
	}
	else if (random == 6)
	{
		return 'J';
	}
	else if (random == 7)
	{
		return 'L';
	}
	else if (random == 8)
	{
		return 'I';
	}
	// control never reaches here
	return 'S';
}

