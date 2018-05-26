/*=============================================================================
 * Program File: utils.cpp
 * Author:  mzc
 * Description: To implement menu utility functions that can be reused
 *              for several assignments
 * ==================================================================================
 */

#include <iostream>
#include <string>
#include <iomanip>
#include "utils.hpp"
#include <cstdlib>  // utilities library - used to convert string to integer
#include <cctype>  // used for character testing function
using namespace std;

/* This function gets input from the user, checks to see if anything other than integers are used
 * and if they are either prompts user to enter integers only,with no zeroes or negative numbers.
 */
int readPositiveInteger(string prompt, int min, int max) {

	string input;  //get input from user
	bool goodInput;
	int numValue;
	do {
		cout << prompt;
		getline(cin, input);

		goodInput = true;
		//loop through the entire length of the input from user
		// if any value entered is not an integer, print error message
		for (unsigned i = 0; i < input.length(); ++i) {
			if (!(isdigit(input.at(i)))) {
				cout << "That is not a positive integer.  Please re-enter\n";
				goodInput = false;
				break;
			}
		}
		numValue = atoi(input.c_str());   //converts string to integer
		//if any zeroes are entered, print error message and allow for correct input
		if (goodInput && (numValue < min || numValue > max)) {
			goodInput = false;
			cout << "Out of bounds. Please re-enter. \n";
		}

	} while (!goodInput);

	return numValue;
}

// function to repeat a set of instructions n times

string replicates(char val, int numTimes) {
	string s;
	while (numTimes--) {
		s += val;
	}
	return s;
}

//dynamically create a 2D array for an n x n matrix
// REMEMBER TO DEALLOCATE THE MEMORY TO PREVENT MEMORY LEAKS

int **createMatrix(int size) {
	int **matrix = new int *[size];
	for (int index = 0; index < size; ++index)
		matrix[index] = new int[size];
	return matrix;
}

// function to display 2D array for an n x n matrix

void showMatrix(int **matrix, int size) {

	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++) {
			cout << setw(5) << matrix[row][col] << " ";
		}
		cout << endl;   //for space between rows
	}
}
