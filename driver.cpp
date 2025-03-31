/// Guga Tchanturia
// Created by Mac on 23.10.24.
// Homework 3

#include <iostream>
#include "Staque.h"

int main() {
    std::cout<< "Test for adding and removing elements: " << std::endl;
    std::cout << " " << std::endl;


    Staque staque;

    // insert numbers into the Staque
    int numbers1[] = {1, 3, 2, 4, 6, 8, 9};
    for (int num : numbers1) {
        staque.add(num);
    }

    // display the Staque after the first set of insertions
    std::cout << "Initial Staque: (front) ";
    staque.display();
    std::cout << "(back)" << std::endl;
    std::cout << "Initial Staque size: " << staque.getSize() << std::endl;

    // delete 2 even numbers and 1 odd number
    staque.remove();  // remove lastly added 9 (odd) from staque
    staque.remove(2, "even"); // remove 2 even numbers

    // display the Staque after deletions
    std::cout << "Staque after deletions: (front) ";
    staque.display();
    std::cout << "(back)" << std::endl;
    std::cout << "Staque size after deletions: " << staque.getSize() << std::endl;

    std::cout << " " << std::endl;

    // example of another input series
    Staque anotherStaque;

    // insert another set of numbers into the second Staque
    int numbers2[] = {10, 12, 15, 13, 11};
    for (int num : numbers2) {
        anotherStaque.add(num);
    }

    // display the second Staque
    std::cout << "Another Staque: (front) ";
    anotherStaque.display();
    std::cout << "(back)" << std::endl;
    std::cout << "Another Staque size: " << anotherStaque.getSize() << std::endl;

    // remove 1 even number and 1 odd
    anotherStaque.remove("odd");
    anotherStaque.remove(1, "even"); // This line is purposefully left as it is to showcase the strict adherence to the LIFO rule of Staque in removal methods
    std::cout << "Another Staque after removing 1 even: (front) ";
    anotherStaque.display();
    std::cout << "(back)" << std::endl;
    std::cout << "Another Staque size after deletions: " << anotherStaque.getSize() << std::endl;

    std::cout << " " << std::endl;

    // another example with mixed numbers
    Staque mixedStaque;
    int numbers3[] = {5, 7, 2, 4, 9, 10};
    for (int num : numbers3) {
        mixedStaque.add(num);
    }

    // display the mixed Staque
    std::cout << "Mixed Staque: (front) ";
    mixedStaque.display();
    std::cout << "(back)" << std::endl;
    std::cout << "Mixed Staque size: " << mixedStaque.getSize() << std::endl;

    // remove 1 odd number and 1 even number
    mixedStaque.remove("odd"); // This line is purposefully left as it is to showcase the strict adherence to the LIFO rule of Staque in removal methods
    mixedStaque.remove(1, "even");
    std::cout << "Mixed Staque after removing 1 odd and 1 even: (front) ";
    mixedStaque.display();
    std::cout << "(back)" << std::endl;
    std::cout << "Mixed Staque size after deletions: " << mixedStaque.getSize() << std::endl;

    std::cout << " " << std::endl;
    std::cout<< "Test for copy constructor and assignment operator: " << std::endl;

    Staque staque1;
    staque1.add(1);
    staque1.add(2);
    staque1.add(3);
    std::cout << "\nOriginal Staque1: ";
    staque1.display();
    std::cout << "\nOriginal Staque1 size: " << staque1.getSize() << std::endl;

    // test Copy Constructor
    Staque staqueCopy = staque1;
    std::cout << "\nCopy Constructed Staque (staqueCopy): ";
    staqueCopy.display();
    std::cout << "\nCopy Constructed Staque (staqueCopy) size: " << staqueCopy.getSize() << std::endl;

    // modify staqueCopy to see if staque1 remains unchanged
    staqueCopy.add(4);
    std::cout << "\nModified Copy (staqueCopy): ";
    staqueCopy.display();
    std::cout << "\nModified Copy (staqueCopy) size: " << staqueCopy.getSize() << std::endl;
    std::cout << "\nOriginal Staque1 should be unchanged: ";
    staque1.display();
    std::cout << "\nOriginal Staque1 size should be unchanged: " << staque1.getSize();


    std::cout << " " << std::endl;

    // test Assignment Operator
    Staque staque2 = staque1;
    std::cout << "\nStaque2 after assignment from Staque1: ";
    staque2.display();
    std::cout << "\nStaque2 size after assignment from Staque1: " << staque2.getSize() << std::endl;

    // modify staque2 to ensure staque1 remains unaffected
    staque2.add(5);
    std::cout << "\nModified Staque2: ";
    staque2.display();
    std::cout << "\nModified Staque2 size: " << staque2.getSize() << std::endl;
    std::cout << "\nOriginal Staque1 should still be unchanged: ";
    staque1.display();
    std::cout << "\nOriginal Staque1 size should still be unchanged: " << staque1.getSize();



    return 0;
}
