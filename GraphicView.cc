#include "GraphicView.h"
#include "View.h"
#include "window.h"
#include <string>

using namespace std;

GraphicView::GraphicView() : w{new Xwindow{}} {}

GraphicView::~GraphicView() {delete w;}

void GraphicView::notify(int x, int y, char c){
	if(c == ' '){ w->fillRectangle(y*20, x*20+80, 20, 20, Xwindow::White);}
	else if(c == 'S'){w->fillRectangle(y*20, x*20+80, 20, 20, Xwindow::LimeGreen);}
	else if(c == 'T'){w->fillRectangle(y*20, x*20+80, 20, 20, Xwindow::Magenta);}
	else if(c == 'L'){w->fillRectangle(y*20, x*20+80, 20, 20, Xwindow::Orange);}
	else if(c == 'J'){w->fillRectangle(y*20, x*20+80, 20, 20, Xwindow::Blue);}
	else if(c == 'O'){w->fillRectangle(y*20, x*20+80, 20, 20, Xwindow::Gold);}
	else if(c == 'Z'){w->fillRectangle(y*20, x*20+80, 20, 20, Xwindow::Red);}
	else if(c == 'I'){w->fillRectangle(y*20, x*20+80, 20, 20, Xwindow::Aqua);}
	else if(c == '*'){w->fillRectangle(y*20, x*20+80, 20, 20, Xwindow::Brown);}
	else if(c == 'C'){w->fillRectangle(y*20, x*20+80, 20, 20, Xwindow::Purple);}
	else if(c == 'N'){w->fillRectangle(y*20, x*20+80, 20, 20, Xwindow::Teal);}
	else{}

}

void GraphicView::update(int level, int score, int highScore, char ch){
	// drawing the stats area here
	drawStats(level, score, highScore);
	// clearing next block area here
	clearNextBlockArea();

	if(ch == 'O'){
		w->fillRectangle(120, 25, 10, 10, Xwindow::Gold );
		w->fillRectangle(130, 25, 10, 10, Xwindow::Gold );
		w->fillRectangle(120, 35, 10, 10, Xwindow::Gold );
		w->fillRectangle(130, 35, 10, 10, Xwindow::Gold );
	}
	else if(ch == 'L'){
		w->fillRectangle(140, 25, 10, 10, Xwindow::Orange );
		w->fillRectangle(120, 35, 10, 10, Xwindow::Orange );
		w->fillRectangle(130, 35, 10, 10, Xwindow::Orange );
		w->fillRectangle(140, 35, 10, 10, Xwindow::Orange );
	}
	else if(ch == 'I'){
		w->fillRectangle(120, 25, 10, 10, Xwindow::Aqua );
		w->fillRectangle(130, 25, 10, 10, Xwindow::Aqua );
		w->fillRectangle(140, 25, 10, 10, Xwindow::Aqua );
		w->fillRectangle(150, 25, 10, 10, Xwindow::Aqua );
	}
	else if(ch == 'J'){
		w->fillRectangle(120, 25, 10, 10, Xwindow::Blue );
		w->fillRectangle(120, 35, 10, 10, Xwindow::Blue );
		w->fillRectangle(130, 35, 10, 10, Xwindow::Blue );
		w->fillRectangle(140, 35, 10, 10, Xwindow::Blue );
	}
	else if(ch == 'Z'){
		w->fillRectangle(120, 25, 10, 10, Xwindow::Red );
		w->fillRectangle(130, 25, 10, 10, Xwindow::Red );
		w->fillRectangle(130, 35, 10, 10, Xwindow::Red );
		w->fillRectangle(140, 35, 10, 10, Xwindow::Red );
	}
	else if(ch == 'S'){
		w->fillRectangle(130, 25, 10, 10, Xwindow::LimeGreen );
		w->fillRectangle(140, 25, 10, 10, Xwindow::LimeGreen );
		w->fillRectangle(120, 35, 10, 10, Xwindow::LimeGreen );
		w->fillRectangle(130, 35, 10, 10, Xwindow::LimeGreen );
	}
	else if(ch == '*'){
		w->fillRectangle(120, 25, 10, 10, Xwindow::Brown );
	}
	else if(ch == 'T'){
		w->fillRectangle(120, 25, 10, 10, Xwindow::Magenta );
		w->fillRectangle(130, 25, 10, 10, Xwindow::Magenta );
		w->fillRectangle(140, 25, 10, 10, Xwindow::Magenta );
		w->fillRectangle(130, 35, 10, 10, Xwindow::Magenta );
	}
	else if(ch == 'N'){
		w->fillRectangle(150, 25, 10, 10, Xwindow::Teal );
		w->fillRectangle(140, 35, 10, 10, Xwindow::Teal );
		w->fillRectangle(130, 45, 10, 10, Xwindow::Teal );
		w->fillRectangle(120, 55, 10, 10, Xwindow::Teal );
	}
	else if(ch == 'C'){
		w->fillRectangle(130, 25, 10, 10, Xwindow::Purple );
		w->fillRectangle(120, 35, 10, 10, Xwindow::Purple );
		w->fillRectangle(130, 35, 10, 10, Xwindow::Purple );
		w->fillRectangle(140, 35, 10, 10, Xwindow::Purple );
		w->fillRectangle(130, 45, 10, 10, Xwindow::Purple );
	}
}

void GraphicView::clearNextBlockArea(){
	w->fillRectangle(120, 25, 10, 10, Xwindow::White );
	w->fillRectangle(130, 25, 10, 10, Xwindow::White);
	w->fillRectangle(140, 25, 10, 10, Xwindow::White);
	w->fillRectangle(150, 25, 10, 10, Xwindow::White);
	w->fillRectangle(120, 35, 10, 10, Xwindow::White );
	w->fillRectangle(130, 35, 10, 10, Xwindow::White );
	w->fillRectangle(140, 35, 10, 10, Xwindow::White);
	w->fillRectangle(130, 45, 10, 10, Xwindow::White );
	w->fillRectangle(120, 55, 10, 10, Xwindow::White );
}

void GraphicView::drawStats(int lev, int score, int highscore){
	//clearing the stats area here
	w->fillRectangle(50,10,13,13, Xwindow::White);
	w->fillRectangle(50,26,13,13, Xwindow::White);
	w->fillRectangle(73,40,13,13, Xwindow::White);
	// converts all the ints to strings then add them to their 
	//corresponding strings
	string levelStr = "Level: " + to_string(lev);
	string scoreStr = "Score: " + to_string(score);
	string highscoreStr = "HighScore: " + to_string(highscore);
	w->drawString(10,20,levelStr);
	w->drawString(10,35,scoreStr);
	w->drawString(10,50,highscoreStr);
	w->drawString(120, 20, "Next:");
}


