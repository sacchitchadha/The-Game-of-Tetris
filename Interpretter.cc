#include "Interpretter.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Game.h"

using namespace std;

Interpretter::Interpretter(Game* g): 
theGame{g}{}

int Interpretter::charToInt(char c){
	if(c >= 48 && c <= 57) return c-48;
	return -1;
}

int Interpretter::getMultiplier(string command){
	int len = command.length();
	int multiplier = 0;
	int numMult = 0;
	int n;
	if(len < 1) return -1;
	for(int i = 0; i < len; ++i){
		n = charToInt(command[i]);
		if(n == -1) continue;
		++numMult;
		multiplier = multiplier*10 + n;
	}
	if(numMult == 0) return 1;
	return multiplier;
	
}



void Interpretter::renameCommand(string defaultCom, string newCom){
	if(isLeft(defaultCom)){ 
		left.clear();
		left.emplace_back(newCom); 
	}
	else if(isRight(defaultCom)){ 
		right.clear();
		right.emplace_back(newCom); }
	else if(isDown(defaultCom)){ 
		down.clear();
		down.emplace_back(newCom); 
	}
	else if(isDrop(defaultCom)){ 
		drop.clear();
		drop.emplace_back(newCom); 
	}
	else if(isClockwise(defaultCom)){ 
		clockwise.clear();
		clockwise.emplace_back(newCom); 
	}
	else if(isCounterclockwise(defaultCom)){ 
		counterclockwise.clear();
		counterclockwise.emplace_back(newCom); 
	}
	else if(isLevelup(defaultCom)){ 
		levelup.clear();
		levelup.emplace_back(newCom); 
	}
	else if(isLeveldown(defaultCom)){ 
		leveldown.clear();
		leveldown.emplace_back(newCom); 
	}
	else if(isRestart(defaultCom)){ 
		restart.clear();
		restart.emplace_back(newCom); 
	}
	else { cout << "command to be renamed is not present" << endl; }

}

void Interpretter::start(){
	readCommands(cin);
}

void Interpretter::readCommands(istream& in){
	string cmds, command;
	while(getline(in, cmds)){
		istringstream s{cmds};
		while(s >> command){
			int n = getMultiplier(command);
			if(n == 0){
				cout << "Congrats, you just wasted a second of your life!" << endl;
				continue;
			}
			removeMultiplier(command);
			if(isLeft(command)){theGame->left(n);}
			else if(isRight(command)){theGame->right(n);}
			else if(isDown(command)){theGame->down(n);}
			else if(isDrop(command)){theGame->drop(n);}
			else if(isRestart(command)){theGame->restart();}
			else if(isClockwise(command)){theGame->clockwise(n);}
			else if(isCounterclockwise(command)){theGame->anticlockwise(n);}
			else if(isLevelup(command)){theGame->levelUp(n);}
			else if(isLeveldown(command)){theGame->levelDown(n);}
			else if(command == "I" || command == "J" || command == "L" 
				|| command == "S" || command == "T" || command == "O" 
				|| command =="Z" || command == "C" 
				|| command == "*" || command == "N")
				{theGame->setCurrBlock(command[0]);}
			else if(isRename(command)){
				string defaultCom, newCom;
				s >> defaultCom >> newCom;
				renameCommand(defaultCom, newCom);
			}
			else if(isSequence(command)){
				string filename;
				s >> filename;
				ifstream f{filename};
				readCommands(f);
			}
			else if(isRandom(command)){theGame->setLevelRandom();}
			else if(isNorandom(command)){
				string filename;
				s >> filename;
				theGame->setLevelNoRandom(filename);
			}
			else { cout << "Invalid command" << endl;}
		}
	}
}

void Interpretter::gameLost(){
	string cmd;
	cout << "You have lost the game, to continue playing enter restart"<<endl;
	while(cin >> cmd){
		removeMultiplier(cmd);
		if(!isRestart(cmd)){
			cout << "You have lost the game, to continue playing enter restart"<<endl;
		}else{
			theGame->restart();
		}
	}
}

void Interpretter::removeMultiplier(string& s){
	int n = getMultiplier(s);
	int len = s.length();
	if(n == 0) return;
	if(n == 1){
		int m = charToInt(s[0]);
		if(m != -1) s = s.substr(1, len-1);
		return;
	}
	int numDigits = 0;
	while(true){
		++numDigits;
		if(n/10 == 0) break;
		n = n/10;
	}
	s = s.substr(numDigits, len-1);
}

bool Interpretter::isLeft(string& s){
	int len = left.size();
	for(int i = 0; i < len; ++i){ 
		if(left[i] == s) return true;
	}
	return false;
}

bool Interpretter::isRight(string& s){
	int len = right.size();
	for(int i = 0; i < len; ++i){ 
		if(right[i] == s) return true;
	}
	return false;
}

bool Interpretter::isDown(string& s){
	int len = down.size();
	for(int i = 0; i < len; ++i){ 
		if(down[i] == s) return true;
	}
	return false;
}

bool Interpretter::isDrop(string& s){
	int len = drop.size();
	for(int i = 0; i < len; ++i){ 
		if(drop[i] == s) return true;
	}
	return false;
}

bool Interpretter::isClockwise(string& s){
	int len = clockwise.size();
	for(int i = 0; i < len; ++i){ 
		if(clockwise[i] == s) return true;
	}
	return false;
}

bool Interpretter::isCounterclockwise(string& s){
	int len = counterclockwise.size();
	for(int i = 0; i < len; ++i){ 
		if(counterclockwise[i] == s) return true;
	}
	return false;
}

bool Interpretter::isRandom(string& s){
	int len = random.size();
	for(int i = 0; i < len; ++i){ 
		if(random[i] == s) return true;
	}
	return false;
}

bool Interpretter::isNorandom(string& s){
	int len = norandom.size();
	for(int i = 0; i < len; ++i){ 
		if(norandom[i] == s) return true;
	}
	return false;
}

bool Interpretter::isSequence(string& s){
	int len = sequence.size();
	for(int i = 0; i < len; ++i){ 
		if(sequence[i] == s) return true;
	}
	return false;
}

bool Interpretter::isLevelup(string& s){
	int len = levelup.size();
	for(int i = 0; i < len; ++i){ 
		if(levelup[i] == s) return true;
	}
	return false;
}

bool Interpretter::isLeveldown(string& s){
	int len = leveldown.size();
	for(int i = 0; i < len; ++i){ 
		if(leveldown[i] == s) return true;
	}
	return false;
}

bool Interpretter::isRestart(string& s){
	int len = restart.size();
	for(int i = 0; i < len; ++i){ 
		if(restart[i] == s) return true;
	}
	return false;
}

bool Interpretter::isRename(string& s){
	int len = rename.size();
	for(int i = 0; i < len; ++i){ 
		if(rename[i] == s) return true;
	}
	return false;
}
















