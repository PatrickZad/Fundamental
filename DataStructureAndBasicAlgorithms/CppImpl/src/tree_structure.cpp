//
// Created by pengcheng.zhang on 2019-08-07.
//
#include "tree_structure.h"
#include "linear_structure.h"
using namespace patrick;
/*
 * Binary node methods implementations
 * */
template <class K, class T>
BinaryNode<K,T>::BinaryNode() {
    data= nullptr;
}

template <class K, class T>
BinaryNode<K,T>::BinaryNode(K key, T *data) {
    this->key=key;
    this->data=data;
}

template <class K, class T>
BinaryNode<K,T>::BinaryNode(BinaryNode<K, T> &node) {
    this->key=node.key;
    this->data=node.data;
}

template <class K, class T>
BinaryNode<K,T>& BinaryNode<K,T>::operator=(const BinaryNode<K, T> &node) {
    key=node.key;
    data=node.data;
    return *this;
}

/*
 * Binary tree methods implementation
 * */

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

template < class K, class T>
void BinaryTree<K,T>::threaded(char order) {
    class ThreadedFunc{
    private:
        BinaryNode<K,T>* last = nullptr;
    public:
        void operator()(BinaryNode<K,T>& node){
            if(node.left == nullptr){
                node.left=last;
            }
            if(last != nullptr && last->right== nullptr){
                last->right=&node;
            }
            last=&node;
        }
    };
    ThreadedFunc func=ThreadedFunc{};
    switch (order){
        case PREORDER_THREADED:
            preOrderTraversalStacking(*this,func);
            break;
        case INORDER_THREADED:
            inOrderTraversalStacking(*this,func);
            break;
        case POSTORDER_THREADED:
            postOrderTraversalStacking(*this,func);
            break;
    }
}

/*
 * Binary search tree methods implementation
 * */
template < class K, class T>
bool BinarySearchTree<K,T>::set(K key, T *data) {

}

template < class K, class T>
T* BinarySearchTree<K,T>::get(K key) {
    BinaryNode<K,T>* node=this->getRoot();
    while (node!= nullptr){
        if(*key==node->key){
            return node->data;
        } else
        if(key>node->key){
            node=node->right;
        } else{
            node=node->left;
        }
    }
    return nullptr;
}
template < class K, class T>
bool BinarySearchTree<K,T>::insert(K key, T& data) {
    BinaryNode<K,T> node=BinaryNode<K,T>{key,data};
    if(this->length==0){
        this->repo.push_back(this->root);
        this->root=&this->repo.back();
        return true;
    }
    BinaryNode<K,T>* parent=this->getRoot();
    while (parent!= nullptr){
        if(key==parent->key){
            return false;
        }
        if(key<parent->key){
            if(parent->left == nullptr){
                this->repo.push_back(this->root);
                parent->left=&this->repo.back();
                this->length++;
                return true;
            } else{
                parent=parent->left;
            }
        } else{
            if (parent->right== nullptr){
                this->repo.push_back(this->root);
                parent->right=&this->repo.back();
                this->length++;
                return true;
            } else{
                parent=parent->right;
            }
        }
    }
}
template < class K, class T>
T* BinarySearchTree<K,T>::remove(K key) {
    BinaryNode<K,T>* node=this->root;
    BinaryNode<K,T>* parent=this->root;
    while (node!= nullptr){
        if (node->key==key){
            break;
        }
        if(node->key>key){
            parent=node;
            node=node->left;
        } else{
            parent=node;
            node=node->right;
        }
    }
    if (node!= nullptr){
        if (node->left==node->right== nullptr){

        }
    } else{
        return nullptr;
    }
}

/*
 * Balanced binary search tree methods implementation
 * */

template < class K, class T>
bool BalancedBinarySearchTree<K,T>::insert(K key, T& data) {
    //TODO
}
template < class K, class T>
T* BalancedBinarySearchTree<K,T>::remove(K key) {
    //TODO
}

/*
 * AVL tree methods implementation
 * */
template < class K, class T>
bool AVLTree<K,T>::insert(K key, T& data) {
    //TODO
}
template < class K, class T>
T* AVLTree<K,T>::remove(K key) {
    //TODO
}
/*
 * RedBlack tree methods implementation
 * */
template < class K, class T>
bool RedBlackTree<K,T>::insert(K key, T& data) {
    //TODO
}
template < class K, class T>
T* RedBlackTree<K,T>::remove(K key) {
    //TODO
}

/*
 * Traversal algorithms
 * */

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


