//
// Created by pengcheng.zhang on 2019-08-07.
//
#include "tree_structure.h"
#include "linear_structure.h"
using namespace patrick;

template <class T>
BinaryTree<T>::BinaryTree() {
    this->length=0;
}
template <class T>
BinaryTree<T>::BinaryTree(T *data) {
    this->root=BinaryNode<T>{data, nullptr, nullptr};
    this->length=1;
}
template <class T>
unsigned int BinaryTree<T>::size() {
    return this->length;
}
template <class T>
BinaryNode<T>* BinaryTree<T>::getRoot() {
    return &(this->root);
}
template <class T, class F>
void preOrderTraversal(BinaryNode<T>& root,F& visitFunc){
    visitFunc(root);
    if(root.left!= nullptr){
        preOrderTraversal(*(root.left),visitFunc);
    }
    if(root.right!= nullptr){
        preOrderTraversal(*(root.right),visitFunc);
    }
}
template <class T,class F>
void preOrderTraversalStacking(BinaryTree<T>& tree,F& visitFunc){
    BinaryNode<T>* ptr=&(tree.getRoot());
    ArrayStack<BinaryNode<T>> stack=ArrayStack<BinaryNode<T>>{};
    while (ptr!= nullptr || stack.size()>0){
        if(ptr!= nullptr){
            visitFunc(*ptr);
            stack.push(*ptr);
            ptr=ptr->left;
        } else{
            ptr=stack.pop()->right;
        }
    }
}
template <class T, class F>
void inOrderTraversal(BinaryNode<T>& root,F& visitFunc){
    if(root.left!= nullptr){
        preOrderTraversal(*(root.left),visitFunc);
    }
    visitFunc(root);
    if(root.right!= nullptr){
        preOrderTraversal(*(root.right),visitFunc);
    }
}
template <class T,class F>
void inOrderTraversalStacking(BinaryTree<T>& tree,F& visitFunc){
    BinaryNode<T>* ptr=&(tree.getRoot());
    ArrayStack<BinaryNode<T>> stack=ArrayStack<BinaryNode<T>>{};
    while (ptr!= nullptr || stack.size()>0){
        if(ptr!= nullptr){
            stack.push(*ptr);
            ptr=ptr->left;
        } else{
            ptr=stack.pop();
            visitFunc(*ptr);
            ptr=ptr->right;
        }
    }
}
template <class T, class F>
void postOrderTraversal(BinaryNode<T>& root,F& visitFunc){
    if(root.left!= nullptr){
        preOrderTraversal(*(root.left),visitFunc);
    }
    if(root.right!= nullptr){
        preOrderTraversal(*(root.right),visitFunc);
    }
    visitFunc(root);
}
template <class T,class F>
void postOrderTraversalStacking(BinaryTree<T>& tree,F& visitFunc){
    //从左子树返回pop和从右子树返回pop做不同处理
    BinaryNode<T>* ptr=&(tree.getRoot());
    ArrayStack<BinaryNode<T>> stack=ArrayStack<BinaryNode<T>>{};
    while (ptr!= nullptr || stack.size()>0){
        if(ptr!= nullptr){
            stack.push(*ptr);
            ptr=ptr->left;
        } else{
            ptr=stack.pop();
            if(ptr->right== nullptr){
                visitFunc(*ptr);
                BinaryNode<T>* parent=stack.pop();
                while (parent->right==ptr){//从右结点返回
                    visitFunc(parent);
                    ptr=parent;
                    parent=stack.pop();
                }
                stack.push(*parent);//从左结点返回
                ptr=parent->right;
            } else{
                stack.push(*ptr);
                ptr=ptr->right;
            }
        }
    }
}
template <class T, class F>
void layerTraversal(BinaryTree<T>& tree, F& visitFunc){
    BinaryNode<T>& node=tree.getRoot();
    ArrayQueue<BinaryNode<T>> queue=ArrayQueue<BinaryNode<T>>{};
    queue.enqueue(node);
    while ((node.left!= nullptr && node.right!= nullptr)
        || queue.size()>0){
        node=*(queue.dequeue());
        visitFunc(node);
        if(node.left!= nullptr){
            queue.enqueue(*(node.left));
        }
        if(node.right!= nullptr){
            queue.enqueue(*(node.right));
        }
    }
}
template <class T>
T* BinarySearchTree<T>::get(unsigned int index) {
    //TODO
}
template <class T>
bool BinarySearchTree<T>::insert(T &data) {
    //TODO
}
template <class T>
T* BinarySearchTree<T>::remove(T &data) {
    //TODO
}
template <class T>
T* BalancedBinarySearchTree<T>::get(unsigned int index) {
    //TODO
}
template <class T>
bool BalancedBinarySearchTree<T>::insert(T &data) {
    //TODO
}
template <class T>
T* BalancedBinarySearchTree<T>::remove(T &data) {
    //TODO
}