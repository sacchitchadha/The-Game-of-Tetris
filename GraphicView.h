#ifndef __GRAPHICVIEW_H__
#define __GRAPHICVIEW_H__
#include <iostream>
class Xwindow;
#include "View.h"

class GraphicView: public View{
	Xwindow *w;
	void clearNextBlockArea();
	void drawStats(int, int, int);
public:
	GraphicView();
	void notify(int, int, char) override;
	void update(int, int, int, char) override;
	~GraphicView();
};
#endif

