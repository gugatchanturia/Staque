# Staque Implementation

## Overview
This repository contains an implementation of the **Staque** data structure using a **doubly linked list**. The name "Staque" refers to a combination of **Stack** and **Deque**, following specific rules for adding and removing elements.

## Features
- Implements **doubly linked list** for efficient traversal.
- Maintains **LIFO** (Last-In, First-Out) behavior.
- Adds elements based on their parity (**even numbers at the front**, **odd numbers at the back**).
- Removes elements with different strategies:
  - Without parameters (LIFO rule)
  - Based on parity (odd/even)
  - Based on count and parity
- Provides utility functions such as **display**, **isEmpty**, and **getSize**.

## Implementation Details

### **Node Class**
The `Node` class represents each element in the Staque. It includes:
- **Data**: Stores the integer value.
- **Pointers**: `prev` and `next` to navigate through the doubly linked list.
- **Index Tracking**:
  - `currentIndex`: Tracks the order of insertion.
  - `ownIndex`: Stores the index at the time of creation (remains unchanged).

#### **Node Constructor**
```cpp
Node(int data)
```
- Initializes `data`.
- Sets `prev` and `next` to `nullptr`.
- Assigns a unique `ownIndex` to track insertion order.

### **Staque Class**
The `Staque` class includes:
- **Attributes**:
  - `first`: Pointer to the first element.
  - `last`: Pointer to the last element.
  - `size`: Tracks the number of elements.

#### **Staque Constructor & Destructor**
```cpp
Staque()
```
- Initializes an empty Staque.

```cpp
~Staque()
```
- Deletes all nodes and resets the structure.

#### **Copy Constructor & Assignment Operator**
```cpp
Staque(const Staque& original)
const Staque& operator=(const Staque& right)
```
- Ensures proper deep copying.
- Prevents memory leaks by clearing the left-hand side before copying.

### **Core Methods**
#### **Adding Elements**
```cpp
void add(int data)
```
- If the Staque is empty, the new node becomes both `first` and `last`.
- If `data` is **even**, it's added to the **front**.
- If `data` is **odd**, it's added to the **back**.
- Updates pointers correctly.

#### **Removing Elements**
```cpp
void remove()
```
- Removes the **most recently added** element (LIFO behavior).

```cpp
void remove(std::string oddOrEven)
```
- Removes the most recent **odd** or **even** element based on the parameter.
- Ensures adherence to LIFO.
- Converts input to lowercase to avoid errors.
- If the requested type is not the most recent, an error is triggered.

```cpp
void remove(int num, std::string oddOrEven)
```
- Removes up to `num` elements matching the given type (`odd` or `even`).
- Ensures it does not remove more elements than available.

#### **Utility Functions**
```cpp
bool isEmpty() const
```
- Returns `true` if the Staque is empty, otherwise `false`.

```cpp
void display() const
```
- Traverses the Staque and prints all elements.

```cpp
int getSize() const
```
- Returns the current size of the Staque.

## **Driver Program (`driver.cpp`)**
The driver program demonstrates the usage of all the above methods with test cases and expected behaviors.

## **Conclusion**
Designing this Staque implementation required careful memory management due to the **doubly linked list** structure. The biggest challenge was ensuring **correct pointer manipulation** while following LIFO rules and managing **dynamic memory allocation** efficiently.

If you have any questions or need clarifications, feel free to reach out!

