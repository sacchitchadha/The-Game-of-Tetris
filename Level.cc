#include "Level.h"
#include <string>
#include <ctime>
#include <fstream>

using namespace std;

Level::Level(int lev, string fileName): 
level{lev}, fileName{fileName}, random{true}{}

int Level::getLevel() { return level; }

Level::~Level() {
	if(!random) file.close();
}

bool Level::isRandom(){ return random; }

void Level::setRandom(){
	if(random) return;
	random = true;
	file.close();
}

void Level::setFile(string newFile){ fileName = newFile; }

void Level::removeRandom(){
	if(!random) return;
	random = false;
	file.open(fileName);
}

char Level::readFromFile(){
	char ch;
	while (true){
		ch = file.get();
		if(ch == EOF){
			file.clear();
			file.seekg(0, ios::beg);
			ch = file.get();
		}
		if(ch == 'L' || ch == 'I' || ch == 'J' || ch == 'O' || 
			ch == 'S' || ch == 'Z' || ch == 'T' || ch == '*' || ch == 'N'
			|| ch == 'C') break;
		continue;
	}
	return ch;
}






