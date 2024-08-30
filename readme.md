# String Management and Move Semantics in C++

This project demonstrates the implementation of a simple `String` class in C++, focusing on dynamic memory management, copy semantics, and move semantics. The `String` class is designed to handle C-style strings (`char*`), with careful attention to memory allocation, copying, and efficient resource transfer using move semantics.

## Features

- **Dynamic Memory Management**: The `String` class handles dynamic memory allocation for storing strings, with appropriate constructors and a destructor to manage the allocated memory.
- **Copy Semantics**: The class includes a copy constructor to safely duplicate `String` objects, ensuring that each instance manages its own copy of the string.
- **Move Semantics**: To enhance performance, the `String` class also includes a move constructor that transfers ownership of resources from temporary objects, avoiding unnecessary deep copies.
- **Entity Class Integration**: The `Entity` class demonstrates how the `String` class can be integrated into other classes, with support for both copy and move semantics.

## Code Overview

### String Class

- **Constructors**:
  - **Explicit Constructor**: Constructs a `String` object from a C-style string (`const char*`), allocating and copying the necessary memory.
  - **Copy Constructor**: Creates a deep copy of an existing `String` object, ensuring that each object manages its own memory.
  - **Move Constructor**: Transfers ownership of resources from a temporary `String` object, leaving the original object in a valid but empty state.
  
- **Destructor**: Cleans up dynamically allocated memory when a `String` object is destroyed.

- **Print Method**: A simple method to output the contents of the `String` object to the console.

### Entity Class

- **Constructors**:
  - **Copy Constructor**: Accepts a `String` object by reference and stores a copy of it.
  - **Move Constructor**: Accepts an rvalue reference to a `String` object, transferring ownership of the string resources to the `Entity` object.

- **Print Method**: Outputs the stored `String` object's contents to the console.

## Usage

To compile and run the project, use the following commands (assuming you have a C++ compiler installed):

```bash
g++ -std=c++11 -o string_entity main.cpp
./string_entity
