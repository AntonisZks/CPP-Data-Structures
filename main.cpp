#include <iostream>
#include <string>
#include "DataStructures/DataStructures.hpp"
using namespace std;

int main(void)
{
    Binary::Tree<int> tree;

    tree.Insert_root(5);
    tree.Insert_left_node(tree.getRoot(), new Binary::TreeNode<int>(4));
    tree.Insert_right_node(tree.getRoot(), new Binary::TreeNode<int>(6));
    
    tree.printPreOrder();
    tree.printInOrder();
    tree.printPostOrder();
    
    return 0;
}