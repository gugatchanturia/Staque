/// Guga Tchanturia
// Created by Mac on 23.10.24.
// Homework 3

#ifndef STAQUE_H
#define STAQUE_H
#include <string>



class Staque {
public:
    class Node {
    public:
        Node * prev;
        Node * next;
        int data;
        static int currentIndex;
        int ownIndex;

        Node(int value);
    };
    // Constructor
    Staque();
    // Destructor
    ~Staque();
    // Assignment operator overloading
    Staque& operator=(const Staque& right);
    // Copy constructor
    Staque(const Staque& original);

    // Adding an element
    void add(int data);
    // Removing with no parameters - removes last element
    void remove();
    // Removing with one element - user must specify whether they want to remove odd or even
    void remove(std::string oddOrEven);
    // Removing with two elements - user specifies how much of a given type odd, or even they want to remove
    void remove(int num, std::string oddOrEven);
    // Is empty method
    bool isEmpty() const;
    // Display method
    void display() const;
    // size getter
    int getSize() const;

private:
    int size;
    Node * first;
    Node * last;


};



#endif //STAQUE_H
