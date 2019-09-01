//
// Created by pengcheng.zhang on 2019-08-07.
//
#include "tree_structure.h"
#include "linear_structure.h"
#include "exception.h"
using namespace patrick;
/*
 * Binary node methods implementations
 * */
template <class K, class T>
BinaryNode<K,T>::BinaryNode(K key, T& data,BinaryNode<K,T>* left, BinaryNode<K,T>* right) {
    this->key=key;
    this->data=data;
    this->left=left;
    this->right= right;
}

template <class K, class T>
DoublyLinkedBinaryNode<K,T>::DoublyLinkedBinaryNode(K key,T& data, BinaryNode<K,T>* parent,
                       BinaryNode<K,T>* left, BinaryNode<K,T>* right){
    this->key=key;
    this->data=data;
    this->left=left;
    this->right= right;
    this->parent=parent;
}

/*
 * Binary tree methods implementation
 * */

template < class K, class T>
BinaryTree<K,T>::BinaryTree() {
    this->length=0;
    this->root= nullptr;
}

template < class K, class T>
BinaryTree<K,T>::~BinaryTree() {
    releaseTree(this->root);
    this->length=0;
}


template < class K, class T>
BinaryTree<K,T>::BinaryTree(const BinaryTree& tree) {
    copyTree(this->root,tree.root);
    this->length=tree.length;
}

template < class K, class T>
BinaryTree<K,T>::BinaryTree(BinaryTree&& tree){
    this->root=tree.root;
    this->length=tree.length;
    tree.root=nullptr;
    tree.length=0;
}

template < class K, class T>
BinaryTree<K,T>& BinaryTree<K,T>::operator=(const BinaryTree& tree){
    releaseTree(this->root);
    this->root= nullptr;
    copyTree(this->root,tree.root);
    this->length=tree.length;
}

template < class K, class T>
BinaryTree<K,T>& BinaryTree<K,T>::operator=(BinaryTree&& tree){
    releaseTree(this->root);
    this->root=tree.root;
    this->length=tree.length;
    tree.root=nullptr;
    tree.length=0;
}

template < class K, class T>
void  BinaryTree<K,T>::copyTree(BinaryNode<K,T>*& objectRoot, BinaryNode<K,T>*& sourceRoot) {
    BinaryNode<K,T>* sourcePtr=sourcePtr;
    objectRoot=new BinaryNode<K,T>{sourcePtr->key,sourcePtr->data};
    ArrayStack<BinaryNode<K,T>> sourceStack=ArrayStack<BinaryNode<K,T>*>{};
    ArrayStack<BinaryNode<K,T>> objectStack=ArrayStack<BinaryNode<K,T>*>{};
    sourceStack.push(sourcePtr);
    objectStack.push(this->root);
    sourcePtr=sourcePtr->left;
    int flag=1;//1 means left, 0 means right
    while (sourcePtr!= nullptr || sourceStack.size()>0){
        if(sourcePtr!= nullptr){
            BinaryNode<K,T>* obj=objectStack.pop();
            if (flag){
                obj->left=new BinaryNode<K,T>{sourcePtr->key,sourcePtr->data};
                objectStack.push(obj);
                objectStack.push(obj->left);
            } else{
                obj->right=new BinaryNode<K,T>{sourcePtr->key,sourcePtr->data};
                objectStack.push(obj);
                objectStack.push(obj->right);
            }
            sourceStack.push(*sourcePtr);
            sourcePtr=sourcePtr->left;
            flag=1;
        } else{
            sourcePtr=sourceStack.pop()->right;
            objectStack.pop();
            flag=0;
        }
    }
}

template < class K, class T>
void  BinaryTree<K,T>::releaseTree(BinaryNode<K,T>*& root) {
    class ReleaseTreeFunc {
    public:
        void operator()(BinaryNode<K,T>* node){
            delete node;
        }
    };
    ReleaseTreeFunc func=ReleaseTreeFunc{};
    postOrderTraversal(root,func);
    root=nullptr;
}

template < class K, class T>
unsigned int BinaryTree<K,T>::size() {
    return this->length;
}

template < class K, class T>
BinaryNode<K,T>* BinaryTree<K,T>::getRoot() {
    return this->root;
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
void BinarySearchTree<K,T>::set(K key, T *data) {

}

template < class K, class T>
T& BinarySearchTree<K,T>::get(K key) {
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
    throw NoSuchKeyExists{};
}
template < class K, class T>
void BinarySearchTree<K,T>::insert(K key, T& data) {
    BinaryNode<K,T>* node=new BinaryNode<K,T>{key,data};
    if(this->length==0){
        this->root=node;
        this->length=1;
        return;
    }
    BinaryNode<K,T>* parent=this->getRoot();
    while (parent!= nullptr){
        if(key==parent->key){
            throw KeyAlreadyExists{};
        }
        if(key<parent->key){
            if(parent->left == nullptr){
                parent->left=node;
                this->length++;
            } else{
                parent=parent->left;
            }
        } else{
            if (parent->right== nullptr){
                parent->right=node;
                this->length++;
            } else{
                parent=parent->right;
            }
        }
    }
}
template < class K, class T>
T BinarySearchTree<K,T>::remove(K key) {
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
void BalancedBinarySearchTree<K,T>::insert(K key, T& data) {
    //TODO
}
template < class K, class T>
T BalancedBinarySearchTree<K,T>::remove(K key) {
    //TODO
}

/*
 * AVL tree methods implementation
 * */
template < class K, class T>
void AVLTree<K,T>::insert(K key, T& data) {
    //TODO
}
template < class K, class T>
T AVLTree<K,T>::remove(K key) {
    //TODO
}
/*
 * RedBlack tree methods implementation
 * */
template < class K, class T>
void RedBlackTree<K,T>::insert(K key, T& data) {
    //TODO
}
template < class K, class T>
T RedBlackTree<K,T>::remove(K key) {
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


