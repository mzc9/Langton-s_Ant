/*=============================================================================
 * Program File: utils.hpp
 * Author:  mzc
 * Description of Program: To implement menu utility functions that can be reused
 *                         for several assignments
 * ==================================================================================
 */

#ifndef UTILS_HPP_
#define UTILS_HPP_
#include <string>

//function prototype to get input for size of array
int readPositiveInteger(std::string, int, int);

// function prototype to dynamically create 2D array for an n x n matrix
int **createMatrix(int size);

//function prototype to display matrix of a 2D array for an n x n matrix
void showMatrix(int **matrix, int size);

std::string replicates(char, int);




#endif /* UTILS_HPP_ */
