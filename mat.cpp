#include "mat.hpp"
#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;
namespace ariel{
    /*
    that func get 2 num and 2 symbol and if indeed meets the conditions 
    the func return string(mat with the two symbol).
    I crate 2 matrix:
    The first take min between i,j;
    0 0 0 0 0
    0 1 1 1 1
    0 1 2 2 2
    0 1 2 3 3
    0 1 2 3 4
    0 1 2 3 4
    0 1 2 3 4
    The second take the min between row - i - 1, col - j - 1:
    4 3 2 1 0
    4 3 2 1 0
    3 3 2 1 0
    2 2 2 1 0
    1 1 1 1 0
    0 0 0 0 0
    next I take the minium betwwn the two matrix:
    0 0 0 0 0       4 3 2 1 0
    0 1 1 1 1       4 3 2 1 0
    0 1 2 2 2  min  4 3 2 1 0
    0 1 2 3 3       3 3 2 1 0
    0 1 2 3 4       2 2 2 1 0
    0 1 2 3 4       1 1 1 1 0
    0 1 2 3 4       0 0 0 0 0
    what create the surface:
    0 0 0 0 0
    0 1 1 1 0
    0 1 2 1 0
    0 1 2 1 0
    0 1 2 1 0
    0 1 1 1 0
    0 0 0 0 0
    Then if the num in the index[i][j] % 2 == 0:
    I append the first symbol.
    else: I append the second symbol
    after every row i append '\n' apart from the last row.(the main append this '\n').
    */
    string mat(int col, int row, char s1, char s2)
    {
        vector<vector<int>> matrix(row, vector<int>(col));
        int const minChar = 33;
        int const maxChar = 126;
        if (row <= 0 || col <= 0)
        {
            throw runtime_error("Mat size is unegative or zero");// check if row or col is negative or zero
        }
        if (row % 2 == 0 || col % 2 == 0)
        {
            throw runtime_error("Mat size is always odd");// check if row or col is even I accept just odd
        }
        if (!(s1 >= minChar && s1 <= maxChar) || !(s2 >= minChar && s2 <= maxChar)) // check if s1 or s2 is unvalid symbol from the ascii table
        {
            throw runtime_error("unvalid symbol");
        }
        string outMat;
        vector<vector<int>> myMat1(row, vector<int>(col));
        vector<vector<int>> myMat2(row, vector<int>(col));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                myMat1[i][j] = min(i, j);
                myMat2[i][j] = min(row - i - 1, col - j - 1);
                myMat1[i][j] = min(myMat1[i][j], myMat2[i][j]);
            }
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if ((myMat1[i][j] % 2) == 0)
                {
                    outMat += s1;
                }
                else
                {
                    outMat += s2;
                }
            }
            if (i != row - 1)
            {
                outMat += '\n';
            }
        }
        return outMat;
    }
}