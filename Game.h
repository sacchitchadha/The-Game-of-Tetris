#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include "window.h"
class GraphicView;
class Interpretter;
class Block;
class Level;
class Board;
class TextView;
class View;
class Score;

class Game {
	Interpretter* theInterpreter;
	Level* currLevel;
	char nextBlockType;
	Block* currBlock;
	Board* theBoard;
	Score* currScore;
	std::string scriptFile;
	int totalRowsCleared, trySinceLastClear;
	bool loss;
	std::vector<View*> displays;
	bool textonly;
	void updateDisplay();
	int rows = 18;
	int columns = 11;
	int startXCoordinate = 3;
	int startYCoordinate = 0;
public:
	Game();
	~Game();
	void left(int);
	void right(int);
	void down(int);
	void drop(int);
	void clockwise(int);
	void anticlockwise(int);
	void levelUp(int);
	void levelDown(int);
	void generateNextBlock();
	void start();
	void restart();
	void lost();
	void setScriptFile(std::string);
	void setLevel(int);
	void setCurrBlock(char);
	void setLevelRandom();
	void setLevelNoRandom(std::string);
	void setTextOnly();
};

#endif

