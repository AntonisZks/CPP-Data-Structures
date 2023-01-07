/* Filename: "Dictionary.hpp" */

/* This file includes all the basic functions
   for a Dictionary Data Structure */

#include <iostream>
#include "Dictionary.hpp"
using namespace std;

template <typename KeyType, typename ValueType>
void Dictionary<KeyType, ValueType>::Add(const KeyType &key, const ValueType &value)
{
    DictionaryNode<KeyType, ValueType> new_node(key, value);
    this->data.Insert(new_node);
    this->size++;
}

template <typename KeyType, typename ValueType>
void Dictionary<KeyType, ValueType>::Remove(const KeyType &key)
{
    /* initializing a current node that holds all the data of the dictionary */
    Singly::Node<DictionaryNode<KeyType, ValueType>> *current_node = this->data.Get_first_node();
    Singly::Node<DictionaryNode<KeyType, ValueType>> *previous_node = this->data.Get_first_node();

    /* Checking if the key is in the first node of the dictionary */
    if (current_node->get_data().getKey() == key)
    {
        this->data.Delete_start();
        this->size--;
    }
    else
    {
        /* Searching for the node containing the given key */
        while (current_node != NULL)
        {
            if (current_node->get_data().getKey() == key)
            {
                previous_node->set_next(current_node->get_next());
                this->data.Update_size();
                this->size--;
                break;
            }
            previous_node = current_node;
            current_node = current_node->get_next();
        }
    }
}

template <typename KeyType, typename ValueType>
ValueType Dictionary<KeyType, ValueType>::Get_value_of(const KeyType &key) const
{
    /* Initializing a current node */
    Singly::Node<DictionaryNode<KeyType, ValueType>> *current_node = this->data.Get_first_node();

    /* Searching for the given key */
    while (current_node != NULL)
    {
        if (current_node->get_data().getKey() == key)
            return current_node->get_data().getValue();
        current_node = current_node->get_next();
    }
    cout << "No key found" << endl;
    ValueType obj;
    return obj;
}

/* Overloading operator << for a Dictionary Node */
template <typename KeyType, typename ValueType>
ostream &operator<<(ostream &out, const DictionaryNode<KeyType, ValueType> &node)
{
    out << node.key << ": " << node.value;
    return out;
}

template <typename KeyType, typename ValueType>
void Dictionary<KeyType, ValueType>::Clear(void)
{
    this->data.Clear();
}

template <typename KeyType, typename ValueType>
void Dictionary<KeyType, ValueType>::Create_from_keys(const Singly::LinkedList<KeyType>& keys, const ValueType& value)
{
    Singly::Node<KeyType>* current_node = keys.Get_first_node();

    while (current_node != NULL)
    {
        this->Add(current_node->get_data(), value);
        current_node = current_node->get_next();
    }
}

/* Overloading operator [] for a Dictionary */
template <typename KeyType, typename ValueType>
ValueType Dictionary<KeyType, ValueType>::operator[](const KeyType& key) const
{
    return this->Get_value_of(key);
}


/* Overloading operator << for a Dictionary */
template <typename KeyType, typename ValueType>
ostream &operator<<(ostream &out, const Dictionary<KeyType, ValueType> &dictionary)
{
    Singly::Node<DictionaryNode<KeyType, ValueType>> *current_node = dictionary.data.Get_first_node();
    out << "{";
    if (dictionary.smart_printing)
    {
        __printing_tabs__++;
        out << endl;
    }
    else
        __printing_tabs__--;
    while (current_node != NULL)
    {
        for (int i = 0; i < __printing_tabs__; i++)
            cout << "    ";
        out << current_node->get_data();
        if (current_node->get_next() != NULL)
        {
            out << ", ";
            if (dictionary.smart_printing)
                out << endl;
        }
        current_node = current_node->get_next();
    }
    if (dictionary.smart_printing)
    {
        out << endl;
        __printing_tabs__--;
    }
    else
        __printing_tabs__++;
    for (int i = 0; i < __printing_tabs__; i++)
        cout << "    ";
    out << "}";
    return out;
}