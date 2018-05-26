/*=============================================================================
 * Program File: grid.cpp
 * Author:  mzc
 * Description:  Implementation of grid class
 * ==================================================================================
 */

#include "grid.hpp"

//member functions to get and set colors of the grid
Grid::Color Grid::getCellColor(int r, int c) {
	return cellColors[r][c];
}
void Grid::setCellColor(Color color, int row, int column) {
	cellColors[row][column] = color;
}

//Constructor to populate the 2D array

Grid::Grid(int nRows, int nCols) {
	rows = nRows;
	cols = nCols;
	cellColors = new Color *[nRows];
	for (int index = 0; index < nRows; ++index) {
		cellColors[index] = new Color[nCols];
		for (int col = 0; col < nCols; ++col) {
			cellColors[index][col] = White;
		}
	}
}

//Destructor for grid to prevent memory leak

//free dynamically allocated memory to prevent memory leak
//(not strictly needed, as we're about to exit anyhow, but included for completeness)
Grid::~Grid() {

	for (int index = 0; index < rows; ++index) {
		delete[] cellColors[index];
	}

	delete[] cellColors;
}

