

# Hash Table-Based Dictionary: Anagram Lookup

## Overview
This project implements a **dictionary** using a custom-built **hash table** for efficient anagram lookups. The project is designed to store words from a dictionary, and enables fast searches to determine if a word is an anagram of any stored word. The hash table uses a dynamically allocated array with linked lists at each bucket, providing an efficient way to manage collisions. This project demonstrates my skills in **algorithm design**, **data structures**, and **C++ programming**. Project for UCLA CS 32 class.

## Features
- **Custom Hash Table**: Built from scratch using the **FNV hashing algorithm** to achieve efficient lookups with evenly distributed values.
- **Anagram Search**: Implements a function to search for anagrams by comparing the sorted versions of strings stored in the dictionary.
- **Word Sanitization**: Handles input by cleaning up non-alphabetical characters and converting uppercase letters to lowercase.
- **Efficient Lookup**: Uses **modulus** and **linked lists** to manage hash collisions while maintaining fast access times.

## Technical Implementation

### Data Structure
- **Hash Table**: The hash table is implemented as an array of buckets. Each bucket is a linked list (using STL `std::list`) that stores words. The hash table allows quick access by hashing the word and storing it in the corresponding bucket.
- **FNV Hashing**: The **Fowler-Noll-Vo** (FNV) hash function is used to hash the words and distribute them across the hash table. This ensures an even distribution of words, minimizing collisions.
- **Linked Lists for Collisions**: In case of hash collisions (multiple words hashed to the same bucket), the words are stored in a linked list, allowing efficient resolution of collisions.

### Key Algorithms
- **Hash Function**: 
  1. Initialize a hash value.
  2. Iterate over each character of the word.
  3. Update the hash using the ASCII value of the character.
  4. Use the modulus operator to map the hash to the appropriate bucket.

- **Word Sanitization**: Converts all uppercase letters to lowercase and removes any non-alphabetical characters from the word before processing.

- **Anagram Detection**: 
  - Sort the characters in the word and compare it with the sorted characters of words stored in the bucket. If they match, the word is an anagram.

## Functions

### `insert(word)`
- **Sanitizes** the word (removes invalid characters, converts to lowercase).
- Hashes the sanitized word using the FNV algorithm.
- **Inserts** the word into the linked list at the appropriate bucket in the hash table.

### `lookup(word, callback)`
- **Sanitizes** and **hashes** the word to find the appropriate bucket.
- Iterates over the words in the linked list.
- If an anagram is found, **executes the callback function** on the word.

## Performance Considerations
The design of this dictionary prioritizes:
- **Fast lookups**: The combination of the FNV hash and linked list resolves collisions effectively while maintaining low lookup times.
- **Memory efficiency**: Using linked lists for each bucket ensures that memory is only allocated as needed, preventing wasted space.

## Pseudocode Highlights
1. **Hash Function**:
    - Initialize hash to a fixed value.
    - For each character in the string:
        - Add the ASCII value of the character to the hash.
        - Multiply the hash by a prime number for distribution.
    - Return the result modulo the number of buckets.

2. **Insert**:
    - Sanitize the word.
    - Hash the word.
    - Place the word in the appropriate bucket (linked list).

3. **Anagram Lookup**:
    - Sanitize and hash the word.
    - For each word in the bucket, check if the sorted characters match the searched word.

## Build and Run

### Requirements
- **C++11** or later
- A compatible C++ compiler (e.g., `g++`)

### Build Instructions
1. Clone this repository.
   
2. Compile the project using a C++ compiler:
   ```bash
   g++ -std=c++11 main.cpp Dictionary.cpp -o dictionary
   ```

3. Run the executable:
   ```bash
   ./dictionary
   ```

## Usage
- **Insert**: Add words to the dictionary using the `insert(word)` method.
- **Lookup**: Search for anagrams using the `lookup(word, callback)` method. If an anagram is found, the callback function will be executed on the matched word.