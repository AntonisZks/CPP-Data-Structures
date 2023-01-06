/* Filename: "Dictionary.hpp" */

/* This file includes all the basic functions
   for a Dictionary Data Structure */

#include <iostream>
#include "Dictionary.hpp"
using namespace std;

template <typename KeyType, typename ValueType>
void Dictionary<KeyType, ValueType>::add(const KeyType &key, const ValueType &value)
{
    DictionaryNode<KeyType, ValueType> new_node(key, value);
    this->data.Insert(new_node);
}

/* Overloading operator << for a Dictionary Node */
template <typename KeyType, typename ValueType>
ostream &operator<<(ostream &out, const DictionaryNode<KeyType, ValueType> &node)
{
    out << node.key << ": " << node.value;
    return out;
}

/* Overloading operator << for a Dictionary */
template <typename KeyType, typename ValueType>
ostream& operator<<(ostream &out, const Dictionary<KeyType, ValueType>& dictionary)
{
    Singly::Node<DictionaryNode<KeyType, ValueType>>* current_node = dictionary.data.Get_first_node();

    out << "{";
    while (current_node != NULL) {
        out << current_node->get_data();
        if (current_node->get_next() != NULL)
            out << ", ";
        current_node = current_node->get_next();
    }
    out << "}";
    return out;
}