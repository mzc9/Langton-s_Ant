/*=============================================================================
 * Program File: grid.hpp
 * Author:  mzc
 * Description: The specification for the grid class.  A grid object creates a
 * 				blank grid with rows and columns and sets row and column colors via
 * 				a 2D array
 * ==================================================================================
 */

#ifndef GRID_HPP_
#define GRID_HPP_

//grid class definitions

class Grid {

public:

	// defined type to hold two possible colors of cell colors for the grid
	enum Color {
		Black, White
	};

	//member functions to get and set grid color
	Color getCellColor(int, int);

	void setCellColor(Color, int, int);

	//Constructor
	Grid(int, int);

	//Destructor
	~Grid();

private:

	//member variable establishing colors of the grid
	//using 2D array to set the two colors of the grid
	Color **cellColors;

	//location on grid
	int rows, cols;
};

#endif /* GRID_HPP_ */
