/* Filename: "Dictionary.hpp" */

/* This file includes all the basic function prototypes
   for a Dictionary Data Structure */

#ifndef DICTIONARY_HEADER
#define DICTIONARY_HEADER

#include <iostream>
#include "../Lists/LinkedList.hpp"
using namespace std;

template <typename KeyType, typename ValueType>
struct DictionaryNode
{
public:
    /* Constructors */
    DictionaryNode(const KeyType& key_, const ValueType& value_): key(key_), value(value_) {}
    DictionaryNode() {} 

    /* Setters */
    void setKey(const KeyType& key) { this->key = key; }
    void setValue(const ValueType& value) { this->value = value }

    /* Getters */
    KeyType getKey() const { return this->key; }
    ValueType getValue() const { return this->value; }

    /* Printing */
    void print() const { cout << "[" << this->key << ": " << this->value << "]" << endl; }

private:
    KeyType key;
    ValueType value;
};

template <typename KeyType, typename ValueType>
class Dictionary
{
public:
    /* Constructor */
    Dictionary() {}

    /* Adding */
    void add(const KeyType& key, const ValueType& value);

    /* Removing */
    void remove(const KeyType key);

    /* Getters */
    ValueType& getValueOf(const KeyType key);

private:
    Singly::LinkedList<DictionaryNode<KeyType, ValueType>> sequence;
};

#endif /* DICTIONARY_HEADER */