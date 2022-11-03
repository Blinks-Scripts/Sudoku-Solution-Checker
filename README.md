README

Sudoku Solution Checker
programmed by Jeffrey Blinks


From Wikipedia "Sudoku"
Sudoku (meaning 'single-digit') is a logic-based,
combinatorial number-placement puzzle. In classic Sudoku,
which is the implementation of this program, the objective
is to fill a 9 x 9 grid with digits so that each column, each row,
and each of the nine 3 x 3 subgrids that compose the
grid (also called "boxes," "blocks," or "regions") contains all
of the digits from 1 to 9.


Sudoku Solution Checker will accept a possible Sudoku
solution and check its validity.

Solutions passed to SSC should be a matrix of integers
contained in a vector of integer vectors.


The function to call is

valid_sudoku( solution )

where solution is a std::vector<std::vector<int>> matrix
containing the solution to check.

Example:
--------

`#include "sudoku_check.cc"
#include "vector"

// create a 9 x 9 solution matrix containing all 0's
std::vector<std::vector<int>> solution( 9, std::vector(9, 0) );

// pass the matrix to the SSC
bool isValidSolution = valid_sudoku( solution );

// isValidSolution == false`

