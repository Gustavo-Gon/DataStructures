
//***********************************************************
// Author: D.S. Malik
//
// This class specifies the members to implement an iterator to a linked list.
// ***********************************************************

#ifndef DATASTRUCTURES_LINKEDLISTITERATOR_H
#define DATASTRUCTURES_LINKEDLISTITERATOR_H
#include <iostream>

//Missing nodeType header?

using namespace std;

template <class Type>
class linkedListIterator {
public:

    //Default constructor
    //Post condition: current = NULL;
    linkedListIterator();

    //Constructor with parameters
    //Post condition: current = ptr;
    linkedListIterator(nodeType<Type> *ptr);

    //Function to overload the dereferencing operator *
    //Post condition: Returns the info contained in the node
    Type operator*();

    //Overloads the preincrement operator
    //Post condition: The iterator is advanced to the next node
    linkedListIterator<Type> operator++();

    //Overload the equality operator
    //Post condition: Returns true if this iterator is equal to the iterator specified by right, otherwise it returns false
    bool operator==(const linkedListIterator<Type>& right) const;

    //Overload the not equal to operator
    //Post condition: Returns true if this iterator is not equal to the iterator specified by right, otherwise returns false.
    bool operator!=(const linkedListIterator<Type>& right) const;

private:
    nodeType<Type> *current; //pointer to point to the current node in the linked list

};

template <class Type>
linkedListIterator<Type>::linkedListIterator() {
    current = NULL;
}

template <class Type>
linkedListIterator<Type>::linkedListIterator(nodeType<Type> *ptr) {
    current = ptr;
}

template <class Type>
Type linkedListIterator<Type>::operator*() {
    return current->info;
}

template <class Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++() {
    current = current->link;

    return *this;
}

template <class Type>
bool linkedListIterator<Type>::operator==(const linkedListIterator<Type> &right) const {
    return (current == right.current);
}

template <class Type>
bool linkedListIterator<Type>::operator!=(const linkedListIterator<Type> &right) const {
    return (current != right.current);
}


#endif //DATASTRUCTURES_LINKEDLISTITERATOR_H
