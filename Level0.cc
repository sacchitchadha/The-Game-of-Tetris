#include "Level0.h"
#include "Level.h"
#include <iostream>
#include <fstream>


using namespace std;

Level0::Level0(string fileName):Level{0, fileName}
{ removeRandom(); }

char Level0::getCharForBlockType() {
	return readFromFile();
}

