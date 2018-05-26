/*==================================================================================
 * Program File: mainAssign1.cpp
 * Author:  mzc
 * Description of Program: To implement a simulation of Langton's Ant, showing the
 * movement of the ant with a change in color based on two rules:
 * 1) in a white square, ant turns right 90 degrees and changes the square from
 *    white to black
 * 2) in a black square, the ant turn left 90 degrees and changes the square from
 *    black to white
 * Input: User-defined:
 * 		  (i) Grid size
 * 		  (ii) The simulation continues for a user-defined number of steps.
 * 	    (iii) Starting location of the ant
 * Output: Along with instructions and prompts, Blank grid with borders on the right
 *         and left delineating the boundaries.
 *         Grid cell if black shown with "#", while white is just blank space
 *         Ant is shown as "*"
 * ==================================================================================
 */

#include <iostream>  //for prompts and user input
#include <limits.h> //to use maximum for int during input validation
#include <unistd.h>  // to use the usleep function

//all the header files for various classes defined
#include "ant.hpp"
#include "grid.hpp"
#include "utils.hpp"
#include "view.hpp"

using namespace std;

Grid::Color flipColor(Grid::Color color) {
	return color == Grid::Black ? Grid::White : Grid::Black;
}

int main() {

	cout
			<< "Welcome to a simulation of Langton's ant.\nFor optimal viewing of this simulation, please select "
			<< "a grid size that fits your viewing window.\nYou will be prompted for number of steps for the simulation. "
			<< "\nThe pattern of ant's movement requires that you select at least 10000 steps.\nYou will also be asked for "
			<< "starting location of the ant on the grid.  \nEnjoy! " << endl;
	cout << endl;

	//call function to get user input for number of rows and columns of the grid

	//Class object of class View
	View view;
	int numRows = view.askHeight(1, INT_MAX);
	int numCols = view.askWidth(1, INT_MAX);
	int numSteps = view.askNumSteps();
	int startRow = view.askStartRow(0, numRows-1);
	int startCol = view.askStartCol(0, numCols-1);

	//Class objects for class Grid and class Ant
	Grid grid(numRows, numCols);
	Ant ant(startRow, startCol, Ant::N);

	//show initial positions/colors
	view.showGrid(numRows, numCols);
	Grid::Color color = grid.getCellColor(startRow, startCol);
	view.drawAnt(color, startRow, startCol);

	//set up for ant movement with change in color based on ant movement
	while (numSteps--) {
		int row = ant.getRow();
		int col = ant.getCol();
		Grid::Color color = grid.getCellColor(row, col);
		Grid::Color newColor = flipColor(color);
		grid.setCellColor(newColor, row, col);
		view.eraseAnt(newColor, row, col);
		if (color == Grid::Black)
			ant.turnLeft();
		else
			ant.turnRight();

		//set up to wrap around when the ant encounters the border of the grid
		// wrap around for all four sides of the grid
		Ant::Direction dir = ant.getDir();
		switch (dir) {
		case Ant::W:
			if (--col < 0)
				col = numCols - 1;
			break;
		case Ant::E:
			col = (col + 1) % numCols;
			break;
		case Ant::N:
			if (--row < 0)
				row = numRows - 1;
			break;
		default:
			row = (row + 1) % numRows;
			break;
		}
		ant.setRow(row);
		ant.setCol(col);
		color = grid.getCellColor(row, col);
		view.drawAnt(color, row, col);
		usleep(10000); // to slow down the ant movement  for better visualization of number of steps
	}

	view.restoreCursor();
	cout<<endl;
	cout << "The simulation has ended.\nAdios, lil' ant! " << endl;
	return 0;
}

