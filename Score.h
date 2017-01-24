#ifndef SCORE_H
#define SCORE_H

class Score {
	int currScore;
	int highScore;
public:
	Score();
	int getCurrScore();
	int getHighScore();
	void incScore(int);
	void resetScore();
};

#endif

