/* Filename: "Dictionary.hpp" */

/* This file includes all the basic function prototypes
   for a Dictionary Data Structure */

#ifndef DICTIONARY_HEADER
#define DICTIONARY_HEADER

#include <iostream>
#include "../Lists/LinkedList.hpp"
using namespace std;

int __printing_tabs__ = 0;

template <typename KeyType, typename ValueType>
struct DictionaryNode
{
public:
    /* Constructors */
    DictionaryNode(const KeyType &key_, const ValueType &value_) : key(key_), value(value_) { }
    DictionaryNode() {}

    /* Setters */
    void setKey(const KeyType &key) { this->key = key; }
    void setValue(const ValueType &value) { this->value = value; }

    /* Getters */
    KeyType getKey() const { return this->key; }
    ValueType getValue() const { return this->value; }

    /* Printing */
    template <typename KeyItem, typename ValueItem>
    friend ostream &operator<<(ostream &out, const DictionaryNode<KeyItem, ValueItem> &node);

private:
    KeyType key;     // Node key
    ValueType value; // Node value
};

template <typename KeyType, typename ValueType>
class Dictionary
{
public:
    /* Constructor */
    Dictionary() { this->smart_printing = false; }

    /* Adding */
    void Add(const KeyType &key, const ValueType &value);

    /* Removing */
    void Remove(const KeyType &key);
    void Clear(void);

    /* Setters */
    void set_smart_printing(const bool value) { this->smart_printing = value; }
    void Create_from_keys(const Singly::LinkedList<KeyType> &keys, const ValueType &value);

    /* Getters */
    ValueType Get_value_of(const KeyType& key) const;

    /* Operator overloading */
    template <typename KeyItem, typename ValueItem>
    friend ostream& operator<<(ostream &out, const Dictionary<KeyItem, ValueItem>& dictionary);

    ValueType operator[](const KeyType& key) const;

private:
    Singly::LinkedList<DictionaryNode<KeyType, ValueType>> data;
    unsigned int size;

    bool smart_printing;
};

#endif /* DICTIONARY_HEADER */