/*==================================================================================
 * Program File: ant.cpp
 * Author:  mzc
 * 
 * Description: Implementation of ant class
 * ==================================================================================
 */


#include "ant.hpp"


//Class implementation

//Constructor

Ant::Ant(int r, int c, Direction d) {
	row = r;
	column = c;
	dir = d;
}

//Member functions for movement of ant
int Ant::getRow() {
	return row;
}

int Ant::getCol() {
	return column;
}
Ant::Direction Ant::getDir() {
		return dir;
	}

// Implementation of the rules of movement for the ant
// since dir is an enum, using static cast for wrap around to work with the use
// of modulo
void Ant::turnRight() {
	dir = static_cast<Direction>((static_cast<int>(dir) + 1) % 4);
}

void Ant::turnLeft() {
	if (dir == E)
		dir = N;
	else
		dir = static_cast<Direction>(static_cast<int>(dir-1));
}
void Ant::setRow(int r) {
	row = r;
}
void Ant::setCol(int c) {
	column = c;
}
