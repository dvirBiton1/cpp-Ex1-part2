/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 *
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: Dvir Biton
 *
 * Date: 2022-03
 */

#include "doctest.h"
#include "mat.hpp"
#include <string>
#include <algorithm>
#include <stdexcept>
using namespace ariel;
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input)
{
    erase(input, ' ');
    erase(input, '\t');
    erase(input, '\n');
    erase(input, '\r');
    return input;
}
//Good input need to return the same as the function
TEST_CASE("Good input")
{
    CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n@-------@\n@-@@@@@-@\n@-@---@-@\n@-@@@@@-@\n@-------@\n@@@@@@@@@"));
    CHECK(nospaces(mat(13, 5, '@', '-')) == nospaces("@@@@@@@@@@@@@\n@-----------@\n@-@@@@@@@@@-@\n@-----------@\n@@@@@@@@@@@@@"));
    CHECK(nospaces(mat(3, 3, '$', '+')) == nospaces("$$$\n$+$\n$$$"));
    CHECK(nospaces(mat(1, 1, '#', ')')) == nospaces("#"));
    CHECK(nospaces(mat(1, 1, ')', '#')) == nospaces(")"));
}
// Mat can't be zero
TEST_CASE("Zero input")
{
    CHECK_THROWS(mat(0, 3, '@', '-'));
    CHECK_THROWS(mat(3, 0, '@', '-'));
    CHECK_THROWS(mat(0, 0, '@', '-'));
}
// Mat can't be egative
TEST_CASE("Negative input")
{
    CHECK_THROWS(mat(-1, 3, '@', '-'));
    CHECK_THROWS(mat(1, -3, '@', '-'));
    CHECK_THROWS(mat(-1, -3, '@', '-'));
}
// Mat size can't be even
TEST_CASE("Even input")
{
    CHECK_THROWS(mat(2, 3, '@', '-'));
    CHECK_THROWS(mat(3, 2, '@', '-'));
    CHECK_THROWS(mat(2, 2, '@', '-'));
}
// Symbol can't be lower the 33 in ASCII TABLE
TEST_CASE("Real symbol input")
{
    CHECK_THROWS(mat(1, 3, '@', '\n'));
    CHECK_THROWS(mat(1, 3, '\n', '-'));
    CHECK_THROWS(mat(1, 3, '\n', '\n'));
    CHECK_THROWS(mat(1, 3, '@', '\t'));
    CHECK_THROWS(mat(1, 3, '\t', '-'));
    CHECK_THROWS(mat(1, 3, '\t', '\t'));
    CHECK_THROWS(mat(1, 3, '@', ' '));
    CHECK_THROWS(mat(1, 3, ' ', '-'));
    CHECK_THROWS(mat(1, 3, ' ', ' '));
    CHECK_THROWS(mat(1, 3, '@', '\r'));
    CHECK_THROWS(mat(1, 3, '\r', '-'));
    CHECK_THROWS(mat(1, 3, '\r', '\r'));
}
//Symbol 1 can't be same as symbol 2
TEST_CASE("Same symbol")
{
    CHECK_THROWS(mat(2, 3, '@', '@'));
}
TEST_CASE("palindrom mat")
{
    string palindrom = nospaces(mat(3, 3, '@', '-'));
    bool flag = true;
    int len = palindrom.length();
    for (int i = 0; i < len / 2; i++)
    {
        if(palindrom[i] != palindrom[len-i-1]){
            cout<<i<<endl;
            cout<<palindrom[i]<<endl;
            cout<<palindrom[len -i]<<endl;
            flag = false;
        }
    }
    CHECK(true == flag);
}
