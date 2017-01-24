#ifndef CELL_H
#define CELL_H


class Cell {
	char charPresent;
public:
	Cell(char = ' ');
	void setChar(char);
	char getChar();
	bool isFree();
	void setFree();
};

#endif

