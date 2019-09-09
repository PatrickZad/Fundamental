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
        BinaryNode(K key,T& data,BinaryNode<K,T>* left = nullptr,
                BinaryNode<K,T>* right = nullptr);
        K key;
        T data;
        BinaryNode<K,T>* left = nullptr;
        BinaryNode<K,T>* right = nullptr;

    };
    /*
     * Doubly-linked BinaryNode
     * */
    template <class K, class T>
    class DLBinaryNode: BinaryNode<K,T>{
    public:
        DLBinaryNode(K key, T& data,
                     DLBinaryNode<K,T>* parent= nullptr,
                     DLBinaryNode<K,T>* left = nullptr,
                     DLBinaryNode<K,T>* right = nullptr);
        DLBinaryNode<K,T>* parent= nullptr;
    };
    /*
     * Doubly-linked BinaryNode with rank
     * */
    template <class K, class T>
    class RankedDLBinaryNode: DLBinaryNode<K,T>{
    public:
        int rank=-1;
    };
    /*
     * Binary tree and its derived classes
     * */

    template <class K, class T>
    class BinaryTree{
    public:
        BinaryTree();
        virtual ~BinaryTree();
        BinaryTree(const BinaryTree& tree);
        BinaryTree(BinaryTree&& tree);
        BinaryTree& operator=(const BinaryTree& tree);
        BinaryTree& operator=(BinaryTree&& tree);
        unsigned int size();
        virtual void set(K key, T* data)=0;
        virtual T& get(K key)=0;
        virtual void insert(K key, T& data)=0;
        virtual T remove(K key)=0;
        void threaded(char order);
        BinaryNode<K, T>* getRoot();
    private:
        void releaseTree(BinaryNode<K,T>*& root);
        void copyTree(BinaryNode<K,T>*& objectRoot, BinaryNode<K,T>*& sourceRoot);
        BinaryNode<K, T>* root;
        unsigned int length;
    };

    template < class K, class T>
    class BinarySearchTree:BinaryTree<K, T>{
    public:
        BinarySearchTree();
        ~BinarySearchTree();
        BinarySearchTree(const BinarySearchTree& tree);
        BinarySearchTree(BinarySearchTree&& tree);
        void set(K key, T& data);
        T& get(K key);
        void insert(K key, T& data);
        T remove(K key);
    };
    template < class K, class T>
    class BalancedBinarySearchTree:BinarySearchTree<K, T>{
    private:
        void restructure(RankedDLBinaryNode<K,T>* node);
        virtual int rankOfNode(RankedDLBinaryNode<K,T>* node)=0;
    };
    template < class K, class T >
    class AVLTree:BalancedBinarySearchTree<K,T>{
    public:
        void insert(K key, T& data);
        T remove(K key);

    private:
        int rankOfNode(RankedDLBinaryNode<K,T>* node);
    };
    template <class K, class T>
    class RedBlackTree:BalancedBinarySearchTree<K,T>{
    public:
        void insert(K key, T& data);
        T remove(K key);

    private:
        int rankOfNode(RankedDLBinaryNode<K,T>* node);
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
