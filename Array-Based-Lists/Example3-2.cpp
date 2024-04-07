//***********************************************************
// Author: D.S. Malik
//
// This program illustrates how a pointer variable works.
// ***********************************************************//


// & is called the address of operator, a unary operator that return the address of its operand
// * used as a unary operator referring to the object to which the operand points to.
#include <iostream>

using namespace std;

int main () {
    int *p;
    int num1 =5;
    int num2 = 8;

    p = &num1;  //store the address of num1 into p;

    cout << "Line 9: &num1 = " << &num1
         << ", p = " << p << endl;
    cout << "Line 10: num1 = " << num1
         << ", *p = " << *p << endl;

    *p = 10;
    cout << "Line 12: num1 = " << num1
         << ", *p = " << *p << endl << endl;

    p = &num2;  //store the address of num2 into p;

    cout << "Line 14: &num2 = " << &num2
         << ", p = " << p << endl;
    cout << "Line 15: num2 = " << num2
         << ", *p = " << *p << endl;

    return 0;
}

