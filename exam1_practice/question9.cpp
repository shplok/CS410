#include <iostream>
#include <string>
using namespace std;


/*
Question Requirements:

Write a C++ program that inputs one number consisting of five digits from the user, then 
separates the number into its individual digits and displays the digits separated from one another
by three spaces each. 
 
 For example, if the user types in the number 42339, the program should
 display 4 2 3 3 9

*/


int main() {
    int inputNum = 0;
    cout << "enter a 5 digit number: ";
    cin >> inputNum;

    string numStr = to_string(inputNum);

    if (numStr.length() < 5 || numStr.length() > 5) {
        cout << "Number input must be 5 digits" << endl;
    } else {
        char arr[10];

        for (int i = 0; i < 5; i++) {
            arr[i*2] = numStr[i];
            arr[i*2+1] = ' ';
        }

        cout << arr << '\n';
    }

    return 0;
}