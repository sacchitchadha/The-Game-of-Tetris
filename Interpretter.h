#ifndef INTERPRETTER_H
#define INTERPRETTER_H

#include <iostream>
#include <string>
#include <vector>
class Game;

class Interpretter {
	Game* theGame;
	std::vector<std::string> left {"lef", "left"};
	std::vector<std::string> right {"right", "righ", "rig", "ri"};
	std::vector<std::string> down {"down", "dow", "do"};
	std::vector<std::string> drop {"drop", "dro", "dr"};
	std::vector<std::string> clockwise 
	{"clockwise", "clockwis", "clockwi", "clockw", "clock", "cloc", "clo", "cl"};
	std::vector<std::string> counterclockwise 
	{"counterclockwise", "counterclockwis", "counterclockwi"};
	std::vector<std::string> levelup 
	{"levelup", "levelu"};
	std::vector<std::string> leveldown 
	{"leveldown", "leveldow", "leveldo", "leveld"};
	std::vector<std::string> restart 
	{"restart", "restar", "resta", "rest", "res"};
	std::vector<std::string> rename 
	{"rename", "renam", "rena", "ren"};
	std::vector<std::string> sequence 
	{"sequence", "sequenc", "sequen", "seque", "sequ", "seq", "se", "s"};
	std::vector<std::string> norandom 
	{"norandom", "norando", "norand", "noran", "nora", "nor", "no", "n"};
	std::vector<std::string> random 
	{"random", "rando", "rand", "ran", "ra"};
	int getMultiplier(std::string);
	int charToInt(char);
	void removeMultiplier(std::string&);
	void renameCommand(std::string, std::string);
	void readCommands(std::istream& in);
	bool isLeft(std::string&);
	bool isRight(std::string&);
	bool isDown(std::string&);
	bool isDrop(std::string&);
	bool isClockwise(std::string&);
	bool isCounterclockwise(std::string&);
	bool isLevelup(std::string&);
	bool isLeveldown(std::string&);
	bool isRestart(std::string&);
	bool isRename(std::string&);
	bool isSequence(std::string&);
	bool isNorandom(std::string&);
	bool isRandom(std::string&);
public:
	Interpretter(Game*);
	void start();
	void gameLost();
};

#endif


