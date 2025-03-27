#include <iostream>
#include <string>
using namespace std;

/* 

Question Requirements:alignas

A palindrome is a number or a text phrase that reads the same backwards as forwards. For
 example, each of the following five-digit integers are palindromes: 12321, 55555, 45554 and
 11611. 
 
 Write a C++ function that takes a five-digit integer and returns a boolean that deter
mines whether the input number is a palindrome. If the number is not five digits, display an
 error message indicating the problem to the user and allow the user to enter a new value.

*/



int main() {
    
    int inputNum = 0;
    cout << "enter a 5 digit number: ";
    cin >> inputNum;
    bool isPalindrome = true;
    string numStr = to_string(inputNum);

    if (numStr.length() < 5 || numStr.length() > 5) {
        cout << "Number input must be 5 digits" << endl;
    } else {
        int l = 0;
        int r = 4;

        while (l < r) {
            if (numStr[l] != numStr[r]) {
                isPalindrome = false;
                break;
            }
            l++;
            r--;
        }
    }

    cout << (isPalindrome ? "True": "False") << '\n';
    return 0;
}
