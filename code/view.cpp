/*==================================================================================
 * Program File: view.cpp
 * Author:  mzc
 * Description: Implementation of view class
 * ==================================================================================
 */
#include <iostream>
#include <limits.h>
#include "ant.hpp"
#include "grid.hpp"
#include "utils.hpp"
#include "view.hpp"
using namespace std;

// prompts for user to get dimensions of grid and also starting location of ant
int View::askWidth(int min, int max) {

	//int min, max;
	return readPositiveInteger("Enter number of columns for the grid\n", min, max);
}
int View::askHeight(int min, int max) {

	return readPositiveInteger("Enter number of rows for the grid\n", min, max);
}
int View::askNumSteps() {

	return readPositiveInteger("Enter number of steps of simulation\n", 1, INT_MAX);
}
int View::askStartRow(int min, int max) {

	return readPositiveInteger("Enter starting row\n", min, max);
}
int View::askStartCol(int min, int max) {

	return readPositiveInteger("Enter starting column\n", min, max);
}

//function to draw the outside border of the grid
void View::showGrid(int numRows, int numCols) {
	for (int nRow = 0; nRow < numRows; ++nRow) {
		cout << "|";

		//call to replicates function from the utils menu functions
		cout << replicates(' ', numCols);
		cout << "|" << endl;
	}

	//establishing the location of cursor
	cursorRow = initRow = numRows;
	cursorCol = initCol = -1;
}
//to move the cursor back to the end of the grid when
// the simulation is complete
void View::restoreCursor() {
	updateCursorPos(initRow, initCol);
}

// the function handles the UNIX cursor position to control ant movement forward
void View::updateCursorPos(int row, int col) {
	int rDelta = cursorRow - row; //change in row position
	int cDelta = cursorCol - col; //change in column position

	if (rDelta > 0)
		cout << "\033[" << rDelta << "A"; //UNIX cursor control command to move up
	else if (rDelta < 0)
		cout << "\033[" << -rDelta << "B"; //UNIX cursor control command to move down
	if (cDelta > 0)
		cout << "\033[" << cDelta << "D"; //UNIX cursor control command to move backward
	else if (cDelta < 0)
		cout << "\033[" << -cDelta << "C"; //UNIX cursor control command to move forward
	cursorRow = row;
	cursorCol = col;
}

void View::drawAnt(Grid::Color color, int row, int col) {
	updateCursorPos(row, col);
	cout << "*";
	cout.flush();  // clears buffer
	++cursorCol;
}

//function to remove ant from existing location and show movement forward
void View::eraseAnt(Grid::Color color, int row, int col) {
	updateCursorPos(row, col);
	cout << (color == Grid::Black ? "#" : " ");  //conditional operator used instead of if/else statement
	cout.flush();
	++cursorCol;
}
