//
// Created by pengcheng.zhang on 2019-08-07.
//

#ifndef CPPIMPL_TREE_STRUCTURE_H
#define CPPIMPL_TREE_STRUCTURE_H

#include "linear_structure.h"
#include <vector>
namespace patrick{
    /*
     * Threded order constants
     * */

    static const char PREORDER_THREADED=0;
    static const char INORDER_THREADED=1;
    static const char POSTORDER_THREADED=2;

    /*
     * Tree node classes
     */

    template <class K, class T>
    class BinaryNode{
    public:
        BinaryNode();
        BinaryNode(K key,T* data);
        BinaryNode(BinaryNode<K,T>& node);
        BinaryNode<K,T>& operator=(const BinaryNode<K,T>& node);
        K key;
        T* data;
        BinaryNode<K,T>* left = nullptr;
        BinaryNode<K,T>* right = nullptr;

    };
    template <class K, class T>
    class DoublyLinkedBinaryNode{
    public:
        DoublyLinkedBinaryNode<K,T>* parent= nullptr;
    };
    template <class K, class T>
    class RankedBinaryNode:BinaryNode<K,T>{
    public:
        int rank;
    };
    /*
     * Binary tree and its derived classes
     * */

    template <class K, class T>
    class BinaryTree{
    public:
        BinaryTree();
        BinaryTree(T* data);
        unsigned int size();
        virtual bool set(K key, T* data)=0;
        virtual T* get(K key)=0;
        virtual bool insert(K key, T& data)=0;
        virtual bool remove(K key)=0;
        void threaded(char order);
        BinaryNode<K, T>* getRoot();
        BinaryNode<K, T>* root;
        //BinaryNode is designed to be accessible only by BinaryTree objects,
        //for which a BinaryTree object should maintain
        // a collection of BinaryNode instances
        //TODO Use vector for now, later change to ExtendableArray
        std::vector<BinaryNode<K,T>> repo=std::vector<BinaryNode<K,T>>{};
    private:
        unsigned int length;
    };

    template < class K, class T>
    class BinarySearchTree:BinaryTree<K, T>{
    public:
        bool set(K key, T* data);
        T* get(K key);
        bool insert(K key, T& data);
        T* remove(K key);
    };
    template < class K, class T>
    class BalancedBinarySearchTree:BinarySearchTree<K, T>{
    public:
        bool insert(K key, T& data);
        T* remove(K key);
    };
    template < class K, class T >
    class AVLTree:BalancedBinarySearchTree<K,T>{
    public:
        bool insert(K key, T& data);
        T* remove(K key);
    };
    template <class K, class T>
    class RedBlackTree:BalancedBinarySearchTree<K,T>{
    public:
        bool insert(K key, T& data);
        T* remove(K key);
    };

    /*
     * Traversal algorithms
     * */
    template < class K, class T,class F>
    void preOrderTraversal(BinaryNode<K, T>& root,F& visitFunc);

    template < class K, class T, class F>
    void preOrderTraversalStacking(BinaryTree<K, T>& tree,F& visitFunc);

    template < class K, class T, class F>
    void inOrderTraversal(BinaryNode<K, T>& root,F& visitFunc);

    template < class K, class T, class F>
    void inOrderTraversalStacking(BinaryTree<K,T>& tree,F& visitFunc);

    template < class K, class T, class F>
    void postOrderTraversal(BinaryNode<K, T>& root,F& visitFunc);

    template < class K, class T, class F>
    void postOrderTraversalStacking(BinaryTree<K, T>& tree, F& visitFunc);

    template < class K, class T, class F>
    void layerTraversal(BinaryTree<K, T>& tree, F& visitFunc);


}
#endif //CPPIMPL_TREE_STRUCTURE_H
