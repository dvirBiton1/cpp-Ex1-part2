#include "mat.hpp"
#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>

using namespace std;
namespace ariel
{
    string mat(int col, int row, char s1, char s2)
    {
        if (row <= 0 || col <= 0)
        {
            throw runtime_error("Mat size is unegative or zero");
        }
        else if (row % 2 == 0 || col % 2 == 0)
        {
            throw runtime_error("Mat size is always odd");
        }
        else if (s1 < 33 || s2 < 33 || s1 > 126 || s2 >126)
        {
            throw runtime_error("unvalid symbol");
        }
        string outMat = "";
        int **myMat1 = new int *[row];
        int **myMat2 = new int *[row];
        for (int i = 0; i < row; ++i)
        {
            myMat1[i] = new int[col];
            myMat2[i] = new int[col];

        }
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
                if (!(myMat1[i][j] % 2))
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
        for (int i = 0; i < row; ++i)
        {
            delete[] myMat1[i];
            delete[] myMat2[i];
        }
        delete[] myMat1;
        delete[] myMat2;
        // cout << "out mat:\n"
        //      << outMat;
        return outMat;
    }
}
