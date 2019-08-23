//
// Created by pengcheng.zhang on 2019-08-07.
//
#include "tree_structure.h"
#include "linear_structure.h"
using namespace patrick;

template < class K, class T>
BinaryTree<K,T>::BinaryTree() {
    this->length=0;
}
template < class K, class T>
BinaryTree<K,T>::BinaryTree(T *data) {
    this->root=BinaryNode<K,T>{data, nullptr, nullptr};
    this->length=1;
}
template < class K, class T>
unsigned int BinaryTree<K,T>::size() {
    return this->length;
}
template < class K, class T>
BinaryNode<K,T>* BinaryTree<K,T>::getRoot() {
    return &(this->root);
}
template < class K, class T, class F>
void preOrderTraversal(BinaryNode<K,T>& root,F& visitFunc){
    visitFunc(root);
    if(root.left!= nullptr){
        preOrderTraversal(*(root.left),visitFunc);
    }
    if(root.right!= nullptr){
        preOrderTraversal(*(root.right),visitFunc);
    }
}
template < class K, class T,class F>
void preOrderTraversalStacking(BinaryTree<K,T>& tree,F& visitFunc){
    BinaryNode<K,T>* ptr=&(tree.getRoot());
    ArrayStack<BinaryNode<K,T>> stack=ArrayStack<BinaryNode<K,T>>{};
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
template < class K, class T, class F>
void inOrderTraversal(BinaryNode<K,T>& root,F& visitFunc){
    if(root.left!= nullptr){
        preOrderTraversal(*(root.left),visitFunc);
    }
    visitFunc(root);
    if(root.right!= nullptr){
        preOrderTraversal(*(root.right),visitFunc);
    }
}
template < class K, class T,class F>
void inOrderTraversalStacking(BinaryTree<K,T>& tree,F& visitFunc){
    BinaryNode<K,T>* ptr=&(tree.getRoot());
    ArrayStack<BinaryNode<K,T>> stack=ArrayStack<BinaryNode<K,T>>{};
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
template < class K, class T, class F>
void postOrderTraversal(BinaryNode<K,T>& root,F& visitFunc){
    if(root.left!= nullptr){
        preOrderTraversal(*(root.left),visitFunc);
    }
    if(root.right!= nullptr){
        preOrderTraversal(*(root.right),visitFunc);
    }
    visitFunc(root);
}
template < class K, class T,class F>
void postOrderTraversalStacking(BinaryTree<K,T>& tree,F& visitFunc){
    //从左子树返回pop和从右子树返回pop做不同处理
    BinaryNode<K,T>* ptr=&(tree.getRoot());
    ArrayStack<BinaryNode<K,T>> stack=ArrayStack<BinaryNode<K,T>>{};
    while (ptr!= nullptr || stack.size()>0){
        if(ptr!= nullptr){
            stack.push(*ptr);
            ptr=ptr->left;
        } else{
            ptr=stack.pop();
            if(ptr->right== nullptr){
                visitFunc(*ptr);
                BinaryNode<K,T>* parent=stack.pop();
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
template < class K, class T, class F>
void layerTraversal(BinaryTree<K,T>& tree, F& visitFunc){
    BinaryNode<K,T>& node=tree.getRoot();
    ArrayQueue<BinaryNode<K,T>> queue=ArrayQueue<BinaryNode<K,T>>{};
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
template < class K, class T>
void BinaryTree<K,T>::threaded(char order) {
    switch (order){
        case PREORDER_THREADED:
            break;
    }
}
template < class K, class T>
T* BinarySearchTree<K,T>::get(K* key) {
    //TODO
}
template < class K, class T>
bool BinarySearchTree<K,T>::insert(T &data) {
    //TODO
}
template < class K, class T>
T* BinarySearchTree<K,T>::remove(T &data) {
    //TODO
}
template < class K, class T>
T* BalancedBinarySearchTree<K,T>::get(K* key) {
    //TODO
}
template < class K, class T>
bool BalancedBinarySearchTree<K,T>::insert(T &data) {
    //TODO
}
template < class K, class T>
T* BalancedBinarySearchTree<K,T>::remove(T &data) {
    //TODO
}