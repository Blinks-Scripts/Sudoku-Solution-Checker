#ifndef SUDOKU_CHECK
#define SUDOKU_CHECK

//****************************************************
//
// Jeffrey Blinks
//
// sudoku check is a function that will accept
// a 9x9 matrix of numbers and check that it
// is a valid sudoku solution (digits 1-9 occuring
// exactly once in each row, column, and each of the
// 9 3x3 'sections' of the solution -- standard sudoku)
//
//*****************************************************

#include <cstdlib>
#include <vector>

const int BOARD_SIZE = 9;
const int BOX_SIZE = 3;

bool line_check( std::vector< std::vector<int> >& );
bool box_check( std::vector< std::vector<int> >& );
bool number_check( std::vector<int>& );

/**
 * check all rows, columns, and boxes
 * that solution is valid
 *
 * @param s The solution vector matrix
 *******************************************/
bool valid_sudoku( std::vector< std::vector<int> > &s )
{
    // All vertical and horizontal components must be legal
    // All 3x3 boxes must be legal
    return ( line_check(s) && box_check(s) );
}

/**
 * check that each row and column
 * is a valid solution
 *
 * @param s The solution vector matrix
 ***************************************/
bool line_check( std::vector< std::vector<int> > &s)
{
    std::vector<int> temp;

    // Individually copy each row into the temp vector
    // and check if each line is a valid solution component
    for ( unsigned int i = 0; i < s.size(); i++ )
    {
        temp = s.at(i);

        // check row solution component
        if ( !number_check(temp) )
            return false;
    }

    // Individually copy each column into the temp vector
    // and check if each line is a valid solution component
    for ( unsigned int k = 0; k < s.at(0).size(); k++ )
    // s.at(0).size() == 9 for a standard sudoku puzzle
    // generic implementation to allow for different sized puzzles
    {
        for ( unsigned int m = 0; m < s.size(); m++ )
        {
            temp.push_back( s.at(m).at(k));
        }

        // check column solution component
        if( !number_check(temp) )
            return false;

        // don't concatenate multiple columns
        // start with an empty vector
        temp.clear();
    }

    return true;
}

/**
 * check that eeach 3x3 square
 * is a valid solution
 *
 * @param s The solution vector matrix
 ***************************************/
bool box_check( std::vector< std::vector<int> > &s )
{
    std::vector<int> temp;

    for ( unsigned int i = 0; i < BOARD_SIZE / BOX_SIZE; i++ )
    {
        for ( unsigned int j = 0; j < BOARD_SIZE / BOX_SIZE; j++ )
        {
            for ( unsigned int k = j*BOX_SIZE; k < (j*BOX_SIZE)+BOX_SIZE; k++ )
            {
                for ( unsigned int m = i*BOX_SIZE; m < (i*BOX_SIZE)+BOX_SIZE; m++ )
                {
                    temp.push_back( s.at(k).at(m) );
                }
            }

            // check box solution component
            if ( !number_check(temp) )
                return false;

            // don't concatenate multiple boxes
            // start with an empty vector
            temp.clear();
        }
    }

    return true;
}

/**
 * verify that a vector contains each
 * digit 1-9 exactly once
 *
 * @param temp A vector of 9 digits
 ***************************************/
bool number_check( std::vector<int> &temp )
{
    int number;

    std::vector<bool> number_switch;
    number_switch.resize( BOARD_SIZE, false );

    /*
     * using number_switch, flip the corresponding
     * digit's bool to true when found.
     * If the bool is already true, the solution
     * has a duplicate number and is invalid, return false
     */
    while ( !temp.empty() )
    {
        number = temp.back();

        if( number_switch.at( number - 1 ) )
            return false;

        number_switch.at( number - 1 ) = true;
        temp.pop_back();
    }

    // if we have not found each digit 1-9
    // return false (perhaps an element contained 0 or 10?)
    for ( unsigned int i = 0; i < BOARD_SIZE; i++ )
    {
        if ( number_switch.at(i) == false )
            return false;
    }

    return true;
}
#endif // SUDOKU_CHECK
