/// Guga Tchanturia
// Created by Mac on 23.10.24.
// Homework 3

#include "Staque.h"

#include <algorithm>
#include <iostream>
// implementation of the Node constructor from the class of node from Staque class
int Staque::Node::currentIndex = 0;

Staque::Node::Node(int value) {
    data = value;
    next = nullptr;
    prev = nullptr;
    ownIndex = ++currentIndex;
}
// implementation of creating Staque as a new object
Staque::Staque() {
    first = nullptr;
    last = nullptr;
    size = 0;
}
// implementation of destructor
Staque::~Staque() {
    Node * temp = first;
    // while the null pointer, in this case the last element, is not reached delete current element and move the pointer to the next one
    while(temp != nullptr) {
        Node * nextptr = temp->next;
        delete temp;
        temp = nextptr;
    }
    first = nullptr;
    last = nullptr;
    size = 0;
}
// implementation of copy constructor
Staque::Staque(const Staque &original) {

    // if the given staque is empty set current as empty also and exit
    if(original.first == nullptr) {
        first = nullptr;
        last = nullptr;
        size = 0;
        return;
    }
    // else copy the first element's data and assign to new staque's first element
    first = new Node(original.first->data);

    // two pointers for each staque to accessing all the elements
    Node * currPtr = first;
    Node * origPtr = original.first->next;

    // while the end of original staque isn't reached copy current element's data from original staque,
    // link it to the existing elements of current staque and move both pointers to their nexts
    while(origPtr != nullptr) {
        Node * newNode = new Node(origPtr->data);
        currPtr->next = newNode;
        newNode->prev = currPtr;
        currPtr = newNode;
        origPtr = origPtr->next;
    }
    // assign the lastly added element to current staque's last
    last = currPtr;
    // assign the original staque's size to the current staque's size
    size = original.size;

}

Staque& Staque::operator=(const Staque &right) {
    // the operations start if the left and right hand side of assignment operator= does not have the same address
    if(this != &right) {
        // destruct the current staque
        this->~Staque();
        // if right staque is empty make the current one empty as well and exit
        if(right.size == 0) {
            first = nullptr;
            last = nullptr;
            size = 0;
            return *this;
        }

        // else copy the first element's data and assign to new staque's first element
        first = new Node(right.first->data);

        // two pointers for each staque to accessing all the elements
        Node * currPtr = first;
        Node * rightPtr = right.first->next;

        // while the end of right staque isn't reached copy current element's data from right staque,
        // link it to the existing elements of left staque and move both pointers to their next's
        while(rightPtr != nullptr) {
            Node * newNode = new Node(rightPtr->data);
            currPtr->next = newNode;
            newNode->prev = currPtr;
            currPtr = newNode;
            rightPtr = rightPtr->next;
        }
        // assign the lastly added element to left staque's last
        last = currPtr;
        // assign the right staque's size to the left staque's size
        size = right.size;
    }
    return *this;
}
// implementation of adding method
void Staque::add(int data) {
    // boolean isEven and new Node is created using the given integer by user
    bool isEven = (data % 2 == 0);
    Node * newNode = new Node(data);

    // if staque is empty assign both first and last to new node
    if(isEmpty()) {
        first = last = newNode;
    }
    // if the list is not empty and number is even add it at the start of staque
    else if(isEven) {
        Node * temp = first;
        first = newNode;
        first->next = temp;
        temp->prev = first;
    }
    // if the list is not empty and number is odd add it at the end of staque
    else {
        newNode->prev = last;
        last->next = newNode;
        last = newNode;
    }
    size++;
}
void Staque::remove() {
    // if the staque is already empty
    if (isEmpty()) return;

    // if there is only one element delete the existing node and set everything to null pointer
    if(size == 1) {
        delete first;
        first = last = nullptr;
    }
    // if there are more than 1 elements remove either first or the last element
    else {
        //first
        if(first->ownIndex > last->ownIndex) {
            Node * temp = first->next;
            delete first;
            first = temp;

        }
        //last
        else {
            Node * temp = last;
            last = last->prev;
            last->next = nullptr;
            delete temp;
        }
    }
    size--;
}
void Staque::remove(std::string oddOrEven) {
    // if the staque is already empty
    if (isEmpty()) return;

    // transforming the parameter provided by user to all lowercase to avoid errors
    std::transform(oddOrEven.begin(), oddOrEven.end(), oddOrEven.begin(), ::tolower);

    // If the size is one and given preference odd or even matches the existing element's type...
    if(size == 1 && ((oddOrEven == "even" && first->data % 2 == 0) || (oddOrEven == "odd" && first->data % 2 != 0))) {
        first = last = nullptr;
    }
    else {
        // This boolean value checks if the first element is the most recently added, therefore !isMostRecent would be if the last is the most recent element added
        bool isFMostRecent = first->ownIndex > last->ownIndex;

        if(oddOrEven == "even" && (first->data % 2 == 0) && isFMostRecent) {
            Node * temp = first->next;
            delete first;
            temp->prev = nullptr;
            first = temp;
            size--;
        }

        else if(oddOrEven == "odd" && (last->data % 2 != 0) && !isFMostRecent) {
            Node * temp = last;
            last = last->prev;
            last->next = nullptr;
            delete temp;
            size--;
        }
        else {
            std::cerr << "\nThe type of element you wish to remove must be the most recently added one! Method: remove(string)" << std::endl;
        }
    }
}
void Staque::remove(int num, std::string oddOrEven) {
    // if the staque is already empty
    if (isEmpty()) return;

    // transforming the parameter provided by user to all lowercase to avoid errors
    std::transform(oddOrEven.begin(), oddOrEven.end(), oddOrEven.begin(), ::tolower);

    // If the size is one and given preference odd or even matches the existing element's type...
    if(size == 1 && ((oddOrEven == "even" && first->data % 2 == 0) || (oddOrEven == "odd" && first->data % 2 != 0))) {
        first = last = nullptr;
    }
    else {
        if(num > size) num = size;
        // while the given number of how much elements to be removed is greater than zero check either first and last and remove it if it's even or odd, respectfully
        while(num > 0) {
            // This boolean value checks if the first element is the most recently added, therefore !isMostRecent would be if the last is the most recent element added
            bool isFMostRecent = first->ownIndex > last->ownIndex;

            if(oddOrEven == "even" && (first->data % 2 == 0) && isFMostRecent) {
                Node * temp = first->next;
                delete first;
                temp->prev = nullptr;
                first = temp;
                size--;
            }
            else if(oddOrEven == "odd" && (last->data % 2 != 0)&& !isFMostRecent) {
                Node * temp = last;
                last = last->prev;
                last->next = nullptr;
                delete temp;
                size--;
            }
            else {
                std::cerr << "\nThe type of element you wish to remove must be the most recently added one! Method: remove(int, string)" << std::endl;
                return; // exits the loop because if the type that the user asked is not the most recent one and can't be deleted, therefore it's next or
                        // previous can't be reached and this return statement avoids redundant operations
            }
            num--;
        }
    }

}
// isEmpty method
bool Staque::isEmpty() const {
    return size == 0;
}
// traverses through staque and displays all elements
void Staque::display() const {
    Node * temp = first;
    while(temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
}
// getSize method for testing in the driver
int Staque::getSize() const {
    return size;
}








