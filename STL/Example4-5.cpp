//***********************************************************
// Author: D.S. Malik
//
// This program illustrates how to use a vector container in a program.
// ***********************************************************

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> intList;
    intList.push_back(13);
    intList.push_back(75);
    intList.push_back(28);
    intList.push_back(35);

    cout << "Line 11: List Elements: ";
    for (int i = 0; i < 4; i++)
        cout << intList[i] << " ";
    cout << endl;

    for (int i = 0; i < 4; i++)
        intList[i] *= 2;

    cout << "Line 17: List Elements: ";
    for (int i = 0; i < 4; i++)
        cout << intList[i] << " ";
    cout << endl;

    vector<int>::iterator listIt;

    cout << "Line 22: List Elements: ";
    for (listIt = intList.begin(); listIt != intList.end(); ++listIt)
        cout << *listIt << " ";
    cout << endl;

    listIt = intList.begin();
    ++listIt;
    ++listIt;
    intList.insert(listIt, 88);

    cout << "Line 30: List Elements: ";
    for (listIt = intList.begin(); listIt != intList.end(); ++listIt)
        cout << *listIt << " ";
    cout << endl;

    return 0;
}