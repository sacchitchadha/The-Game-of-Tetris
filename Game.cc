#include "Game.h"
#include "Interpretter.h"
#include "Block.h"
#include "Level.h"
#include "TextView.h"
#include "Score.h"
#include "Board.h"
#include "Coords.h"
#include "Level0.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"
#include "Level4.h"
#include "SpecialBlock.h"
#include "SBlock.h"
#include "OBlock.h"
#include "ZBlock.h"
#include "TBlock.h"
#include "JBlock.h"
#include "LBlock.h"
#include "iblock.h"
#include "CBlock.h"
#include "NBlock.h"
#include "Level5.h"
#include "GraphicView.h"
#include "View.h"
#include <string>
#include <ctime>
#include <stdexcept>

#include <iostream>

using namespace std;

int MAXLEVEL = 5;

Game::Game(): textonly{false}, loss{false}{
	theInterpreter = new Interpretter{this};
	displays.emplace_back(new TextView{rows, columns});
	theBoard = new Board
	{rows, columns, Coords{startXCoordinate, startYCoordinate}, displays};
	currScore = new Score;
	scriptFile = "sequence.txt"; // setting default file to read from
	currLevel = nullptr;
}

Game::~Game() { 
	delete theInterpreter;
	delete theBoard;
	delete currBlock;
	delete currScore;
	delete currLevel;
	int len = displays.size();
	for(int i = 0; i < len; ++i){delete displays[i];}
	displays.clear();
}

void Game::left(int n){ 
	int level = currLevel->getLevel(); 
	for(int i = 0; i < n; ++i){
		currBlock->moveLeft();
	}
	if(level == 3 || level == 4) currBlock->moveDown();
	updateDisplay();
}

void Game::right(int n){
	int level = currLevel->getLevel();
	for(int i =0; i < n; ++i){
		currBlock->moveRight();
	}
	if(level == 3 || level == 4) currBlock->moveDown();
	updateDisplay();
}

void Game::down(int n){ 
	int level = currLevel->getLevel();
	for(int i = 0; i < n; ++i){
		currBlock->moveDown();
	}
	if(level == 3 || level ==4) currBlock->moveDown();
	updateDisplay();
}

void Game::drop(int n){
	for(int i = 0; i < n; ++i){
		currBlock->drop();
		int scoreInc = theBoard->updateScore(currLevel->getLevel());
		currScore->incScore(scoreInc);
		if(theBoard->getTotalRowsCleared() > totalRowsCleared){
			totalRowsCleared = theBoard->getTotalRowsCleared();
			trySinceLastClear = 0;
		}else{
			++trySinceLastClear;
		}
		if(trySinceLastClear >= 5 && currLevel->getLevel() == 4){
			nextBlockType = '*';
			trySinceLastClear = 0;
		}
		updateDisplay();
		generateNextBlock();
		if(loss) return;
	}
}

void Game::clockwise(int n){
	int level = currLevel->getLevel();
	for(int i = 0; i < n; ++i){
		currBlock->clockwise(); 
	}
	if(level == 3 || level ==4) currBlock->moveDown();
	updateDisplay();
}

void Game::anticlockwise(int n){ 
	int level = currLevel->getLevel();
	for(int i = 0; i < n; ++i){
		currBlock->anticlockwise();
	}
	if(level == 3 || level ==4) currBlock->moveDown();
	updateDisplay(); 
}

void Game::levelUp(int n){
	for(int i = 0; i < n; ++i){
		int currLevelNum = currLevel->getLevel();
		//updateDisplay();
		setLevel(currLevelNum+1);
		//updateDisplay();
	}
	updateDisplay();
}

void Game::levelDown(int n){
	for(int i = 0; i < n; ++i){
		int currLevelNum = currLevel->getLevel();
		// delete currLevel;
		setLevel(currLevelNum-1);
	}
	updateDisplay();
}

void Game::setLevel(int levelNum){
	Level* tmp = currLevel;
	if(levelNum < 0) levelNum = 0; // checking if level is in the correct range
	if(levelNum > MAXLEVEL) levelNum = MAXLEVEL; // checking if level is in the correct range
	if(levelNum == 0){ currLevel = new Level0{scriptFile}; }
	else if(levelNum == 1) { currLevel = new Level1{scriptFile}; }
	else if(levelNum == 2) { currLevel = new Level2{scriptFile}; }
	else if(levelNum == 3) { currLevel = new Level3{scriptFile}; }
	else if(levelNum == 4) { currLevel = new Level4{scriptFile}; }
	else if(levelNum == 5) { currLevel = new Level5{scriptFile}; }
	else {}
	delete tmp;
}

void Game::setScriptFile(string fileName){ scriptFile = fileName; }

void Game::generateNextBlock(){
	int levelNum = currLevel->getLevel();
	// if else statements to set it to its new value
	try{
		if(nextBlockType=='I'){currBlock = new IBlock{theBoard, levelNum};}
		else if(nextBlockType=='S'){currBlock = new SBlock{theBoard, levelNum};}
		else if(nextBlockType=='Z'){currBlock = new ZBlock{theBoard, levelNum};}
		else if(nextBlockType=='T'){currBlock = new TBlock{theBoard, levelNum};}
		else if(nextBlockType=='O'){currBlock = new OBlock{theBoard, levelNum};}
		else if(nextBlockType=='J'){currBlock = new JBlock{theBoard, levelNum};}
		else if(nextBlockType=='L'){currBlock = new LBlock{theBoard, levelNum};}
		else if(nextBlockType=='C'){currBlock = new CBlock{theBoard, levelNum};}
		else if(nextBlockType=='N'){currBlock = new NBlock{theBoard, levelNum};}
		else if(nextBlockType=='*'){
			currBlock = new SpecialBlock{theBoard, levelNum};
			nextBlockType = currLevel->getCharForBlockType();
			drop(1);
		}
		else{}
	}catch(out_of_range){
		currBlock = nullptr;
		loss = true;
		lost();
	}
	// update nextBlockType
	nextBlockType = currLevel->getCharForBlockType();
	updateDisplay();
}

void Game::start(){
	if(!textonly){
		GraphicView* gv = new GraphicView;
		displays.emplace_back(gv);
		theBoard->addView(gv);
	}
	if(!currLevel) currLevel = new Level0{scriptFile};
	nextBlockType = currLevel->getCharForBlockType();
	generateNextBlock();
	theInterpreter->start();
	
}

void Game::lost(){
	theInterpreter->gameLost();
}

void Game::restart(){
	theBoard->clearBoard();
	currScore->resetScore();
	delete currBlock;
	nextBlockType = currLevel->getCharForBlockType();
	generateNextBlock();
	theInterpreter->start();    
}

void Game::updateDisplay(){
	int level = currLevel->getLevel();
	int cscore = currScore->getCurrScore();
	int hscore = currScore->getHighScore();
	int len = displays.size();
	for(int i = 0; i < len; ++i){
		displays[i]->update(level, cscore, hscore, nextBlockType);
	}
}

void Game::setCurrBlock(char c) { 
	nextBlockType = c;
	currBlock->removeItFromBoard();
	delete currBlock;
	generateNextBlock();
}

void Game::setLevelRandom(){
	int lev = currLevel->getLevel();
	if(lev == 3 || lev == 4) currLevel->setRandom();
}

void Game::setLevelNoRandom(string fileName){
	int lev = currLevel->getLevel();
	if(lev == 3 || lev == 4){
		currLevel->setFile(fileName);
		currLevel->removeRandom();
	}

}

void Game::setTextOnly(){ textonly = true; }


