#ifndef COORDS_H
#define COORDS_H

class Coords {
	int x, y;
public:
	Coords(int = -1, int = -1);
	void setX(int);
	void setY(int);
	int getX();
	int getY();
	void incX();
	void decX();
	void incY();
	void decY();
	bool operator == (Coords);
};

#endif

