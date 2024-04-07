
//***********************************************************
// Author: D.S. Malik
//
// This program illustrates how to allocate dynamic memory
// using a pointer variable and how to manipulate data into // that memory location.
// ***********************************************************

#include <iostream>

using namespace std;

int main () {
    int *p;
    int *q;

    p = new int;
    *p = 34;
    cout << "Line 9: p = " << p
         << ", *p = " << *p << endl;

    q = p;
    cout << "Line 11: q = " << q
         << ", *q = " << *q << endl;

    *q = 45;
    cout << "Line 13: p = " << p
         << ", *p = " << *p << endl;
    cout << "Line 14: q = " << q
         << ", *q = " << *q << endl;

    p = new int;
    *p = 18;
    cout << "Line 17: p = " << p
         << ", *p = " << *p << endl;
    cout << "Line 18: q = " << q
         << ", *q = " << *q << endl;

    delete q;
    q = NULL;
    q = new int;
    *q = 62;
    cout << "Line 23: p = " << p
         << ", *p = " << *p << endl;
    cout << "Line 24: q = " << q
         << ", *q = " << *q << endl;

    return 0;
}