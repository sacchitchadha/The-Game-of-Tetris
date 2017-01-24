#ifndef BOARD_H
#define BOARD_H

#include "Cell.h"
#include <vector>
#include "Coords.h"
class View;
class Block;


class Board{
	std::vector<View*> displays;
	std::vector<std::vector<Cell>> theBoard;
	std::vector<Block*> aliveBlocks;
	Coords startCoords;
	int numRows, numCols, totalRowsCleared;

	bool isRowFilled(int);
	void clearRows();
	void deleteAliveBlocks();

public:
	Board(int, int, Coords, std::vector<View*>); 
	// for level, rows, cols, startCoords
	~Board();
	int updateScore(int);
	void updateCell(int, int, char);
	Coords getStartCoords();
	void addToAliveBlocks(Block*);
	void clearBoard();
	bool isFree(Coords);
	void clearCell(int, int);
	int getTotalRowsCleared();
	void addView(View*);
};

#endif

