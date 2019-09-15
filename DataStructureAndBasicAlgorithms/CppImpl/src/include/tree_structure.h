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
        BinaryNode(K& key,T& data,BinaryNode<K,T>* left = nullptr,
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
    class DLBinaryNode: public BinaryNode<K,T>{
    public:
        DLBinaryNode(K& key, T& data,
                     DLBinaryNode<K,T>* parent= nullptr,
                     DLBinaryNode<K,T>* left = nullptr,
                     DLBinaryNode<K,T>* right = nullptr);
        DLBinaryNode<K,T>* parent= nullptr;
    };
    /*
     * Doubly-linked BinaryNode with rank
     * */
    template <class K, class T>
    class RankedDLBinaryNode: public DLBinaryNode<K,T>{
    public:
        RankedDLBinaryNode(K& key, T& data,int rank=-1,
                     RankedDLBinaryNode<K,T>* parent= nullptr,
                     RankedDLBinaryNode<K,T>* left = nullptr,
                     RankedDLBinaryNode<K,T>* right = nullptr);
        int rank=-1;
    };

    /*
     * Binary tree and its derived classes
     * */

    template <class K, class T>
    class BinaryTree{
        /*
         * Use BinaryNode as element type
         * */
    public:
        BinaryTree();

        virtual ~BinaryTree();

        BinaryTree(const BinaryTree& tree);

        BinaryTree(BinaryTree&& tree);

        BinaryTree& operator=(const BinaryTree& tree);
        /*
         * universal for all derived classes
         * */
        BinaryTree& operator=(BinaryTree&& tree);
        /*
         * universal for all derived classes
         * */
        unsigned int size();

        virtual void set(K key, T* data)=0;

        virtual T& get(K key)=0;

        virtual void insert(K key, T& data)=0;

        virtual T remove(K key)=0;
        /*
         * universal for all derived classes
         * */
        void threaded(char order);

        virtual BinaryNode<K, T>* getRoot();
    protected:

        BinaryNode<K, T>* root;

        unsigned int length;
    };

    template < class K, class T>
    class BinarySearchTree: public BinaryTree<K, T>{
        /*
         *use BinaryNode as element type
         */
    public:

        ~BinarySearchTree();

        BinarySearchTree(const BinarySearchTree& tree);

        BinarySearchTree(BinarySearchTree&& tree);

        BinarySearchTree& operator=(const BinarySearchTree& tree);

        /*
         * universal for its derived class
         * */
        void set(K key, T& data);
        /*
         * universal for its derived class
         * */
        T& get(K key);

        void insert(K key, T& data);

        T remove(K key);
    };

    template < class K, class T>
    class BalancedBinarySearchTree : public BinarySearchTree<K, T>{
        /*
         *use DLBinaryNode as element type
         */
    public:
        ~BalancedBinarySearchTree();

        BalancedBinarySearchTree(const BalancedBinarySearchTree& tree);

        BalancedBinarySearchTree(BalancedBinarySearchTree&& tree);

        BalancedBinarySearchTree& operator=(const BalancedBinarySearchTree& tree);

    private:
        void restructure(DLBinaryNode<K,T>* node);
        virtual int rankOfNode(DLBinaryNode<K,T>* node)=0;
    };

    template < class K, class T >
    class AVLTree : public BalancedBinarySearchTree<K,T>{
        /*
         *use RankedDLBinaryNode as element type
         */
    public:
        ~AVLTree();
        AVLTree(const AVLTree& tree);
        AVLTree(AVLTree&& tree);
        AVLTree& operator=(const AVLTree& tree);
        void insert(K key, T& data);
        T remove(K key);

    private:
        int rankOfNode(RankedDLBinaryNode<K,T>* node);
    };

    template <class K, class T>
    class RedBlackTree : public BalancedBinarySearchTree<K,T>{
        /*
         *use RankedDLBinaryNode as element type
         */
    public:
        ~RedBlackTree();
        RedBlackTree(const RedBlackTree& tree);
        RedBlackTree(RedBlackTree&& tree);
        RedBlackTree& operator=(const RedBlackTree& tree);
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

    /*
     * other assistant functions
     * */
    template <class K, class T>
    BinaryNode<K,T>* copyTree(BinaryNode<K,T>* root);
    template <class K, class T>
    DLBinaryNode<K,T>* copyTree(DLBinaryNode<K,T>* root);
    template <class K, class T>
    RankedDLBinaryNode<K,T>* copyTree(RankedDLBinaryNode<K,T>* root);

    template <class K, class T>
    void releaseTree(BinaryNode<K,T>* root);

}
#endif //CPPIMPL_TREE_STRUCTURE_H
