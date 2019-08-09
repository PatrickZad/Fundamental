//
// Created by pengcheng.zhang on 2019-08-07.
//
#include "tree_structure.h"
using namespace patrick;
template <class T>
BinaryTree<T>::BinaryTree() {
    this->length=0;
}
template <class T>
unsigned int BinaryTree<T>::size() {
    return this->length;
}
