#include "mat.hpp"
#include <string>
#include <iostream>
// #include <algorithm>
#include <stdexcept>
#include <vector>
// #include <typeinfo>
// #include <ctype.h>

using namespace std;
namespace ariel{

    /*
    that func get 2 num and 2 symbol שnd if indeed meets the conditions 
    the func return string(mat with the two symbol).
    */
    string mat(int col, int row, char s1, char s2)
    {
        vector<vector<int>> matrix(row, vector<int>(col));
        int const minChar = 33;
        int const maxChar = 126;
        int number = 1;
        if (row <= 0 || col <= 0)
        {
            throw runtime_error("Mat size is unegative or zero");
        }
        if (row % 2 == 0 || col % 2 == 0)
        {
            throw runtime_error("Mat size is always odd");
        }
        // if (typeid(col).name() != typeid(number).name() || typeid(row).name() != typeid(number).name())
        // {
        //     throw runtime_error("problame with the type of int");
        // }
        if (!(s1 >= minChar && s1 <= maxChar))
        {
            throw runtime_error("unvalid symbol");
        }
        if (!(s2 >= minChar && s2 <= maxChar))
        {
            throw runtime_error("unvalid symbol");
        }
        string outMat;
        // int **myMat1 = new int *[row];
        // int **myMat2 = new int *[row];
        // for (int i = 0; i < row; ++i)
        // {
        //     myMat1[i] = new int[col];
        //     myMat2[i] = new int[col];

        // }
        vector<vector<int>> myMat1(row, vector<int>(col));
        vector<vector<int>> myMat2(row, vector<int>(col));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                myMat1[i][j] = min(i, j);
                myMat2[i][j] = min(row - i - 1, col - j - 1);
                myMat1[i][j] = min(myMat1[i][j], myMat2[i][j]);
                // cout << myMat1[i][j];
            }
            // cout << endl;
        }
        // for (int i = 0; i < row; i++)
        // {
        //     for (int j = 0; j < col; j++)
        //     {
        //         myMat2[i][j] = min(row - i - 1, col - j - 1);
        //         cout<<myMat2[i][j];
        //     }
        //     cout<<endl;
        // }
        // cout << "end\n";
        // for (int i = 0; i < row; i++)
        // {
        //     for (int j = 0; j < col; j++)
        //     {
        //         myMat1[i][j] = min(myMat1[i][j], myMat2[i][j]);
        //         cout<<myMat1[i][j];
        //     }
        //     cout<<endl;
        // }
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
        // for (int i = 0; i < row; ++i)
        // {
        //     delete[] myMat1[i];
        //     delete[] myMat2[i];
        // }
        // delete[] myMat1;
        // delete[] myMat2;
        // cout << "out mat:\n"
        //      << outMat;
        return outMat;
    }
}