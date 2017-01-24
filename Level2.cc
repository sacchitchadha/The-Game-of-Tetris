#include "Level2.h"
#include <cstdlib>

using namespace std;

Level2::Level2(string fileName) : Level{2, fileName} {}

char Level2::getCharForBlockType(){
	if(!isRandom()){
		return readFromFile();
	}
	int random = rand() % 7;

	if (random == 0)
	{
		return 'S';
	}
	else if (random == 1)
	{
		return 'Z';
	}
	else if (random == 2)
	{
		return 'O';
	}
	else if (random == 3)
	{
		return 'T';
	}
	else if (random == 4)
	{
		return 'I';
	}
	else if (random == 5)
	{
		return 'T';
	}
	else if (random == 6)
	{
		return 'I';
	}else{
		
	}
	// control never reaches here
	return 'Q';
}

