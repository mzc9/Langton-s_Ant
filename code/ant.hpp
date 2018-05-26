/*=========================================================================================
 * Program File: ant.hpp
 * Author:  mzc
 * 
 * Description: The specification file for the ant class.
 * 				An ant is an object that participates in the simulation of Langton's Ant.
 * 				This ant model places the ant at a user-defined location on the grid.
 * 				If the ant encounters a black cell, it turns 90 degrees to the left and changes
 *         the color of the cell it is leaving.  If it encounters a white cell,
 *           it turns 90 degrees to the right.
 * =========================================================================================
 */

#ifndef ANT_HPP_
#define ANT_HPP_

//Ant class declaration

class Ant {

public:
	//defined type to hold direction of movement for the ant object
	// assigned values to be able to use modulo operator
	enum Direction {
		E = 0, S = 1, W = 2, N = 3
	};
	//Constructor that takes the row, col and direction of movement
	Ant(int r, int c, Direction d);


	int getRow();
	int getCol();

	Direction getDir();

	void turnLeft();
	void turnRight();

	void setRow(int);
	void setCol(int);

private:
	//variable of type Direction
	Direction dir;

//Location of Ant
	int row, column;
};


#endif /* ANT_HPP_ */
