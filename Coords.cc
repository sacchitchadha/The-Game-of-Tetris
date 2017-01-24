#include "Coords.h"

Coords::Coords(int x, int y): x{x}, y{y} {}

int Coords::getX() {return x;}

int Coords::getY() {return y;}

void Coords::setX(int newX) { x = newX; }

void Coords::setY(int newY) { y = newY; }

void Coords::incX() { ++x; }

void Coords::incY() { ++y; }

void Coords::decX() { --x; }

void Coords::decY() { --y; }

bool Coords::operator==(Coords other){
	return (x == other.getX() && y == other.getY());
}

