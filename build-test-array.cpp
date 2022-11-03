// Created by Jeffrey Blinks
//
// Builds a 9x9 matrix with
// values 1-9 in each row
//

#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>

void print_sudoku( std::vector<std::vector<int>> &vec )
{
    int colbreak = 0;
    int rowbreak = 0;
    for ( auto it = vec.begin(); it != vec.end(); ++it)
    {
        while ( !(*it).empty() )
        {
            do
            {
                std::cout << it->back();
                it->pop_back();
                colbreak++;
            } while ( colbreak % 3 > 0 );
            if ( colbreak % 9 == 0 )
            {
                std::cout << "\n";
                if ( ++rowbreak % 3 == 0 )
                    std::cout << "\n";
            }
            else
                std::cout << " ";
        }
    }
}

std::vector<std::vector<int>> build_matrix()
{
    std::vector<std::vector<int>> row( 9, std::vector<int>( 9, 0 ));

    std::for_each( row.begin(), row.end(), [](auto &vec){
             std::for_each(vec.begin(), vec.end(),[](int &n){
                      static int i = 0;
                      n = ( i++ % 9 + 1);
                      });
                      });

    return row;
}

/*
int main(){

    auto m = build_matrix();
    print_sudoku( m );

    return 0;
}
*/
