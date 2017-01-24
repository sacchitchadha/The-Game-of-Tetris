#include "Score.h"

Score::Score(): currScore{0}, highScore{0} {}

int Score::getCurrScore() { return currScore; }

int Score::getHighScore() { return highScore; }

void Score::incScore(int incBy) { 
	currScore += incBy; 
	if(currScore > highScore) highScore = currScore;
}

void Score::resetScore() { currScore = 0; }


