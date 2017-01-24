#include "Block.h"
#include "LBlock.h"
#include "Coords.h"
#include "Board.h"
#include <stdexcept>
#include <vector>

using namespace std;

LBlock::LBlock(Board *b,int level) :Block{b, level}{
	blockType ='L';
	int startX = theBoard->getStartCoords().getX();
	int startY = theBoard->getStartCoords().getY();
	theCoords.emplace_back(Coords{startX+1, startY});
	theCoords.emplace_back(Coords{startX+1, startY+1}); 
	theCoords.emplace_back(Coords{startX+1, startY+2}); 
	theCoords.emplace_back(Coords{startX, startY+2});  

	if(!isCoordsFreeOnBoard()) throw out_of_range{"L"};

    // update the board
	updateBoard();
}

void LBlock::config1ToConfig2() {
	theCoords[0].setX(theCoords[0].getX()-2);
	theCoords[0].setY(theCoords[0].getY());
	theCoords[1].setX(theCoords[1].getX()-1);
	theCoords[1].setY(theCoords[1].getY()-1);
	theCoords[2].setX(theCoords[2].getX());
	theCoords[2].setY(theCoords[2].getY()-2);
	theCoords[3].setX(theCoords[3].getX()+1);
	theCoords[3].setY(theCoords[3].getY()-1);

}

void LBlock::config2ToConfig3() {
	theCoords[0].setX(theCoords[0].getX()+1);
	theCoords[0].setY(theCoords[0].getY()+2);
	theCoords[1].setX(theCoords[1].getX());
	theCoords[1].setY(theCoords[1].getY()+1);
	theCoords[2].setX(theCoords[2].getX()-1);
	theCoords[2].setY(theCoords[2].getY());
	theCoords[3].setX(theCoords[3].getX());
	theCoords[3].setY(theCoords[3].getY()-1);

}

void LBlock::config3ToConfig4() {
	theCoords[0].setX(theCoords[0].getX()+1);
	theCoords[0].setY(theCoords[0].getY()-1);
	theCoords[1].setX(theCoords[1].getX());
	theCoords[1].setY(theCoords[1].getY());
	theCoords[2].setX(theCoords[2].getX()-1);
	theCoords[2].setY(theCoords[2].getY()+1);
	theCoords[3].setX(theCoords[3].getX()-2);
	theCoords[3].setY(theCoords[3].getY());

}

void LBlock::config4ToConfig1() {
	theCoords[0].setX(theCoords[0].getX());
	theCoords[0].setY(theCoords[0].getY()-1);
	theCoords[1].setX(theCoords[1].getX()+1);
	theCoords[1].setY(theCoords[1].getY());
	theCoords[2].setX(theCoords[2].getX()+2);
	theCoords[2].setY(theCoords[2].getY()+1);
	theCoords[3].setX(theCoords[3].getX()+1);
	theCoords[3].setY(theCoords[3].getY()+2);

}

void LBlock::config1ToConfig4() {
	theCoords[0].setX(theCoords[0].getX());
	theCoords[0].setY(theCoords[0].getY()+1);
	theCoords[1].setX(theCoords[1].getX()-1);
	theCoords[1].setY(theCoords[1].getY());
	theCoords[2].setX(theCoords[2].getX()-2);
	theCoords[2].setY(theCoords[2].getY()-1);
	theCoords[3].setX(theCoords[3].getX()-1);
	theCoords[3].setY(theCoords[3].getY()-2);

}

void LBlock::config2ToConfig1() {
	theCoords[0].setX(theCoords[0].getX()+2);
	theCoords[0].setY(theCoords[0].getY());
	theCoords[1].setX(theCoords[1].getX()+1);
	theCoords[1].setY(theCoords[1].getY()+1);
	theCoords[2].setX(theCoords[2].getX());
	theCoords[2].setY(theCoords[2].getY()+2);
	theCoords[3].setX(theCoords[3].getX()-1);
	theCoords[3].setY(theCoords[3].getY()+1);

}

void LBlock::config3ToConfig2() {
	theCoords[0].setX(theCoords[0].getX()-1);
	theCoords[0].setY(theCoords[0].getY()-2);
	theCoords[1].setX(theCoords[1].getX());
	theCoords[1].setY(theCoords[1].getY()-1);
	theCoords[2].setX(theCoords[2].getX()+1);
	theCoords[2].setY(theCoords[2].getY());
	theCoords[3].setX(theCoords[3].getX());
	theCoords[3].setY(theCoords[3].getY()+1);

}

void LBlock::config4ToConfig3() {
	theCoords[0].setX(theCoords[0].getX()-1);
	theCoords[0].setY(theCoords[0].getY()+1);
	theCoords[1].setX(theCoords[1].getX());
	theCoords[1].setY(theCoords[1].getY());
	theCoords[2].setX(theCoords[2].getX()+1);
	theCoords[2].setY(theCoords[2].getY()-1);
	theCoords[3].setX(theCoords[3].getX()+2);
	theCoords[3].setY(theCoords[3].getY());

}

void LBlock::clockwise(){
	// clear coords from board
	clearCoordsOnBoard();
	// make clockwise changes
	if(presentConfig==1){
		presentConfig=2;
		config1ToConfig2();
	}
	else if(presentConfig==2){
		presentConfig=3;
		config2ToConfig3();

	}
	else if (presentConfig==3){
		presentConfig=4;
		config3ToConfig4();
	}
	else{
		presentConfig=1;
		config4ToConfig1();
	}

	// check if coords are free on board
	if(!isCoordsFreeOnBoard()){
		// make anticlockwise changes
		if(presentConfig==1){
			presentConfig=4;
			config1ToConfig4();
		}else if(presentConfig==2){
			presentConfig=1;
			config2ToConfig1();
		}else if(presentConfig==3){
			presentConfig=2;
			config3ToConfig2();
		}else{
			presentConfig=3;
			config4ToConfig3();
		}
	}
	// finally update the board
	updateBoard();
}

void LBlock::anticlockwise(){
	// clear coords from board
	clearCoordsOnBoard();
	// make anticlockwise changes
	if(presentConfig==1){
		presentConfig=4;
		config1ToConfig4();
	}
	else if(presentConfig==2){
		presentConfig=1;
		config2ToConfig1();
	}
	else if (presentConfig==3){
		presentConfig=2;
		config3ToConfig2();
	}
	else{
		presentConfig=3;
		config4ToConfig3();
	}

	// check if coords are free on board
	if(!isCoordsFreeOnBoard()){
		// make clockwise changes
		if(presentConfig==1){
			presentConfig=2;
			config1ToConfig2();
		}else if(presentConfig==2){
			presentConfig=3;
			config2ToConfig3();
		}else if(presentConfig==3){
			presentConfig=4;
			config3ToConfig4();
		}else{
			presentConfig=1;
			config4ToConfig1();
		}
	}
	// finally update the board
	updateBoard();
}



