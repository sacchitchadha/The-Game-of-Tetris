#include "Cell.h"


Cell::Cell(char toFill):charPresent{toFill} {}

void Cell::setChar(char toSet) { charPresent = toSet; }

char Cell::getChar() { return charPresent; }

bool Cell::isFree() { return charPresent == ' ' ;}

void Cell::setFree() { charPresent = ' '; }
		
