/**
 * Main program for mat exercise.
 * 
 * Author: Dvir Biton
 * Since : 2022-03
 */

#include "mat.hpp"

#include <iostream>
#include <stdexcept>
using namespace std;
using namespace ariel;

int main() {
	cout << ariel::mat(9, 7, '@', '-') << endl;
/* Should print:
@@@@@@@@@
@-------@
@-@@@@@-@
@-@---@-@
@-@@@@@-@
@-------@
@@@@@@@@@
*/
	cout << ariel::mat(13, 5, '@', '-') << endl; 
/* Should print:
@@@@@@@@@@@@@
@-----------@
@-@@@@@@@@@-@
@-----------@
@@@@@@@@@@@@@
*/
	try {
		cout << ariel::mat(10, 5, '$', '%') << endl; // Exception - not a valid code
	} catch (exception& ex) {
	 	cout << "   caught exception: " << ex.what() << endl;  // should print "Mat size is always odd"
	}
int col;
int row;
char s1;
char s2;
cout<<"Enter the odd number for the col:"<<endl;
cin>>col;
cout<<"Enter the odd number for the row:"<<endl;
cin>>row;
cout<<"Enter char for s1:"<<endl;
cin>>s1;
cout<<"Enter char for s2:"<<endl;
cin>>s2;
cout<<"The result:"<<endl;
cout<<mat(col,row,s1,s2)<<endl;
return 0;
}
