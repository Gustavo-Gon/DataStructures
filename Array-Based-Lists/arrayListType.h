
//***********************************************************
// Author: D.S. Malik
//
// This class specifies the members to implement the basic
// properties of array-based lists.
// ***********************************************************

#ifndef DATASTRUCTURES_ARRAYLISTTYPE_H
#define DATASTRUCTURES_ARRAYLISTTYPE_H
#include <iostream>

using namespace std;

template <class elemType>
class arrayListType {
public:

    //Overloads the assignment operator
    const arrayListType<elemType> &operator=(const arrayListType<elemType> &);

    //Function to determine whether the list is empty
    //Post condition: Returns true if the list is empty, otherwise returns false
    bool isEmpty() const;

    //Function to determine whether the list is full
    //Post condition: Returns true if list is full, otherwise returns false
    bool isFull() const;

    //Function to determine the number of elements in the list
    //Post condition: Returns the value of length
    int listSize() const;

    //Function to determine the size of the list
    //Post condition: Returns the value of maxSize
    int maxListSize() const;

    //Function to output the elements of the list
    //Post condition: Elements of the list are output on the standard output device
    void print() const;

    //Function to determine whether the item is the same as the item in the list at the position specified
    //Post condition: Returns true if list[location] is the same as the item, otherwise returns false
    bool isItemAtEqual(int location, const elemType &item) const;

    //Function to insert an item in the list at the position specified by location
    //The item inserted is passed as a parameter to the function
    //Post condition: Starting at location, the elements of the list are shifted down
    // list[location] = insertItem;,and length++;. If the list is full or location is
    // out of range, an appropriate message is displayed.
    void insertAt(int location, const elemType &insertItem);

    //Function to insert an item at the end of the list
    //The parameter insertItem specifies the item to be inserted.
    // Post condition: list[length] = insertItem; and length++;
    // If the list is full, an appropriate message is displayed.
    void insertEnd(const elemType &insertItem);

    //Function to remove the item from the list at the position specified by location
    //Post condition: The list element at list[location] is removed
    // and length is decremented by 1. If location is out of range, an appropriate message is displayed.
    void removeAt(int location);

    //Function to retrieve the element from the list at the //position specified by location.
    //Post condition: retItem = list[location], if location is out of range, an appropriate message is displayed.
    void retrieveAt(int location, elemType &retItem) const;

    //Function to replace the elements in the list at the position specified by location.
    //The item to be replaced is specified by the parameter repItem.
    //Post condition: list[location] = repItem, if location is out of range, an appropriate message is displayed.
    void replaceAt(int location, const elemType &repItem);

    //Function to remove all the elements from the list, after this operation, the size of the list is zero.
    // Post condition: length = 0;
    void clearList();

    //Function to search the list for a given item.
    //Post condition: If the item is found, returns the location in the array where the item is found; otherwise, returns -1.
    int seqSearch(const elemType &item) const;

    //Function to insert the item specified by the parameter //insertItem at the end of the list.
    //However, first the list is searched to see whether the item to be inserted is already in the list.
    //Post condition: list[length] = insertItem and length++i
    // if the item is already in the list or the list is full, an appropriate message is displayed.
    void insert(const elemType &insertItem);

    //Function to remove an item from the list. The parameter removeItem specifies the item to be removed.
    //Post condition: If removeItem is found in the list, it is removed from the list and length is decremented by one.
    void remove(const elemType &removeItem);

    //Constructor
    //Creates an array of the size specified by the parameter size. The default array size is 100.
    //Post condition: The list points to the array, length = 0, and maxSize = size
    arrayListType(int size = 100);

    //Copy constructor
    arrayListType(const arrayListType<elemType> &otherList);

    //Destructor
    //Deallocates the memory occupied by the array
    ~arrayListType();

protected:
    elemType *list; //array tp hold the list elements
    int length;     //to store the length of the list
    int maxSize;    //to store the maximum size of the list
};

template <class elemType> //O(1)
bool arrayListType<elemType>::isEmpty() const {
    return (length == 0);
}

template <class elemType> //O(1)
bool arrayListType<elemType>::isFull() const {
    return (length == maxSize);
}

template <class elemType> //O(1)
int arrayListType<elemType>::listSize() const {
    return length;
}

template <class elemType> //O(1)
int arrayListType<elemType>::maxListSize() const {
    return maxSize;
}

template <class elemType> //O(n)
void arrayListType<elemType>::print() const {
    for (int i = 0; i < length; i++)
        cout << list[i] << " ";

    cout << endl;
}

template <class elemType> //O(1)
bool arrayListType<elemType>::isItemAtEqual(int location, const elemType &item) const {
    return(list[location] == item);
}

template <class elemType> //O(n)
void arrayListType<elemType>::insertAt(int location, const elemType &insertItem) {
    if (location < 0 || location >= maxSize)
        cerr << "The position of the item to be inserted "
             << "is out of range" << endl;
    else
        if (length >= maxSize) //list is full
            cerr << "Cannot insert in a full list" << endl;
        else {
            for (int i = length; i > location; i--)
                list[i] = list[i - 1];          //move the elements down
                list[location ] = insertItem;   //insert the item at the specified position
                length++;                       //increment the length
        }
}  //end insertAt

template <class elemType> //O(1)
void arrayListType<elemType>::insertEnd(const elemType &insertItem) {
    if (length >= maxSize)  //the list is full
        cerr << "Cannot insert in a full list" << endl;
    else {
        list[length] = insertItem; //insert the item at the end
        length++;   //increment the length
    }
} //end insertEnd

template <class elemType> //O(n)
void arrayListType<elemType>::removeAt(int location) {
    if (location < 0 || location >= length)
        cerr << "The location of the item to be removed "
             << "is out of range" << endl;
    else {
        for (int i = location; i < length - 1; i++)
            list[i] = list[i++];
        length--;
    }
} //end removeAt

template <class elemType> //O(1)
void arrayListType<elemType>::retrieveAt(int location, elemType &retItem) const {
    if (location < 0 || location >= length)
        cerr << "The location of the item to be retrieved is "
             << "out of range." << endl;
    else
        retItem = list[location];
} //end retrieveAt

template <class elemType> //O(n)
void arrayListType<elemType>::replaceAt(int location, const elemType &repItem) {
    if (location < 0 || location >= length)
        cerr << "The location of the item to be replaced is "
             << "out of range." << endl;
    else
        list[location] = repItem;
} //end replaceAt

template <class elemType> //O(1)
void arrayListType<elemType>::clearList() {
    length = 0;
} //end clearList

template <class elemType> //O(1)
arrayListType<elemType>::arrayListType(int size) {
    if (size < 0) {
        cerr << "The array size must be positive. Creating "
             << "an array of size 100. " << endl;
        maxSize = 100;
    }
    else
        maxSize = size;

    length = 0;
    list = new elemType[maxSize];
    assert(list != NULL);
}

template <class elemType> //O(1)
arrayListType<elemType>::~arrayListType() {
    delete [] list;
}

template <class elemType> //O(n)
arrayListType<elemType>::arrayListType(const arrayListType<elemType>& otherList) {
    maxSize = otherList.maxSize;
    length = otherList.length;
    list = new elemType[maxSize];   //create the array
    assert(list != NULL);           //terminate if unable to allocate memory space

    for (int j = 0; j < length; j++) //copy otherList
        list [j] = otherList.list[j];
} //end copy constructor

template <class elemType> //O(n)
const arrayListType<elemType>& arrayListType<elemType>::operator=(const arrayListType<elemType> &otherList) {
    if  (this != &otherList) { //avoid self-assignment
        delete [] list;
        maxSize = otherList.maxSize;
        length = otherList.length;

        list = new elemType[maxSize]; //create the array
        assert(list != NULL);         //if unable to allocate memory space, terminate the program

        for (int i = 0; i < length; i++)
            list[i] = otherList.list[i];
    }
    return *this;
}

template <class elemType> //O(n)
int arrayListType<elemType>::seqSearch(const elemType &item) const {
    int loc;
    bool found = false;

    for (loc = 0; loc < length; loc++)
        if (list[loc] == item) {
            found = true;
            break;
        }
    if (found)
        return loc;
    else
        return -1;
} //end seqSearch

template <class elemType> //O(n)
void arrayListType<elemType>::insert(const elemType &insertItem) {
    int loc;
    if (length == 0) //list is empty
        list[length++] = insertItem; //insert the item and increment the length

    else if (length == maxSize)
        cerr << "Cannot insert in a full list." << endl;
    else {
        loc = seqSearch(insertItem);
        if (loc == -1) //the item to be inserted does not exist in the list
            list[length++] = insertItem;
        else
            cerr << "the item to be inserted is already in "
                 << "the list. No duplicates are allowed." << endl;
    }
} //end insert

template <class elemType> //O(n)
void arrayListType<elemType>::remove(const elemType &removeItem) {
    int loc;

    if (length == 0)
        cerr << "Cannot delete from an empty list." << endl;
    else {
        loc = seqSearch(removeItem);

        if (loc != -1)
            removeAt(loc);
        else
            cout << "The item to be deleted is not in the list." << endl;
    }
} //end remove


#endif //DATASTRUCTURES_ARRAYLISTTYPE_H
