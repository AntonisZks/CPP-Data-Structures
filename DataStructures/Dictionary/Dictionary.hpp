/* Filename: "Dictionary.hpp" */

/* This file includes all the basic function prototypes
   for a Dictionary Data Structure */

#ifndef DICTIONARY_HEADER
#define DICTIONARY_HEADER

#include <iostream>
#include "../Lists/LinkedList.hpp"
using namespace std;

int __printing_tabs__ = 0;

/* Basic Class of a Dictionary Node */
template <typename KeyType, typename ValueType>
struct DictionaryNode
{
public:
    /* Constructors */
    DictionaryNode() {}                                                                        // Default Constructor
    DictionaryNode(const KeyType &key_, const ValueType &value_) : key(key_), value(value_) {} // Complex Constructor

    /* Setters */
    void setKey(const KeyType &key) { this->key = key; }           // Sets the key of the node
    void setValue(const ValueType &value) { this->value = value; } // Sets the value of the node

    /* Getters */
    KeyType getKey() const { return this->key; }       // Returns the key of the node
    ValueType getValue() const { return this->value; } // Returns the value of the node

    /* Printing */
    template <typename KeyItem, typename ValueItem>
    friend ostream &operator<<(ostream &out, const DictionaryNode<KeyItem, ValueItem> &node);

private:
    KeyType key;     // Node key
    ValueType value; // Node value
};

/* Basic Class of a Dictionary */
template <typename KeyType, typename ValueType>
class Dictionary
{
public:
    /* Constructor */
    Dictionary() { this->smart_printing = false; } // Default constructor

    /* Adding */
    void Add(const KeyType &key, const ValueType &value); // Adds a key and its value to the dictionary

    /* Removing */
    void Clear(void);                // Removes all the data from the dictionary
    void Remove(const KeyType &key); // Removes the given key and its value from the dictionary

    /* Setters */
    void Set_value_of(const KeyType &key, const ValueType &value);                          // Sets the given value of the given key
    void Set_smart_printing(const bool value) { this->smart_printing = value; }             // Controls the smart printing of the dictionary
    void Create_from_keys(const Singly::LinkedList<KeyType> &keys, const ValueType &value); // Creates the dictinary from a given singly linked list containing the keys
    void Create_from_keys(const Doubly::LinkedList<KeyType> &keys, const ValueType &value); // Creates the dictinary from a given doubly linked list containing the keys

    /* Getters */
    ValueType Get_value_of(const KeyType &key) const; // Returns the value of the given key

    /* Operator overloading */
    template <typename KeyItem, typename ValueItem>
    friend ostream &operator<<(ostream &out, const Dictionary<KeyItem, ValueItem> &dictionary);

    ValueType &operator[](const KeyType &key) const;
    void operator=(const Dictionary<KeyType, ValueType> &other);

    /* Other Methods */
    Dictionary Copy(void); // Returns a copy of the dictionary

private:
    Singly::LinkedList<DictionaryNode<KeyType, ValueType>> data; // Dictionary data (keys and values)
    unsigned int size;                                           // Size of the dictionary
    bool smart_printing;                                         // Boolean value for smart printing or no
};

#endif /* DICTIONARY_HEADER */