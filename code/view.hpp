/*==================================================================================
 * Program File: view.hpp
 * Author:  mzc
 * Description: Specifications for the view class.
 *              The view class uses the grid model and utils classes to get input
 *              from the user for size of grid, number of steps of simulation and
 *              starting location of the ant.
 * 				The view class also controls the cursor via the UNIX cursor functions.
 * 				This cursor control allows for tracking the ant't movement without
 * 				resorting to re-drawing the grid each time.
 * ==================================================================================
 */

#ifndef VIEW_HPP_
#define VIEW_HPP_


#include "utils.hpp"

//View class declarations

class View {

//Member variables for cursor movement and for starting location of ant
private:
	int cursorRow, cursorCol, initRow, initCol;
	void updateCursorPos(int row, int col);


	//Member functions
public:
//functions to get user input for grid and initial ant position
	int askWidth(int, int);
	int askHeight(int, int);
	int askNumSteps();
	int askStartRow(int, int);
	int askStartCol(int, int);

	void showGrid(int, int);
	void drawAnt(Grid::Color, int, int);
	void eraseAnt(Grid::Color, int, int); //function to show ant is moving forward
	void restoreCursor();                 // to ensure the cursor ends up at the correct location when the simulation ends
};

#endif /* VIEW_HPP_ */

