//
// Created by pengcheng.zhang on 2019-08-07.
//

#ifndef CPPIMPL_TREE_STRUCTURE_H
#define CPPIMPL_TREE_STRUCTURE_H
namespace patrick{
    static const char PREORDER_THREADED=0;
    static const char INORDER_THREADED=1;
    static const char POSTORDER_THREADED=2;
    template <class K, class T>
    class BinaryNode{
    public:
        BinaryNode();
        BinaryNode(K key,T* data);
        K key;
        T* data;
        BinaryNode* left;
        BinaryNode* right;
    };
    template <class K, class T>
    class BinaryTree{
    public:
        BinaryTree();
        BinaryTree(T* data);
        unsigned int size();
        virtual T* get(K* key)=0;
        virtual bool insert(T& data)=0;
        virtual T* remove(T& data)=0;
        void threaded(char order);
        BinaryNode<K, T>* getRoot();
    private:
        unsigned int length;
        BinaryNode<K, T> root;
    };
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
    template < class K, class T>
    class BinarySearchTree:BinaryTree<K, T>{
    public:
        T* get(K* key);
        bool insert(T& data);
        T* remove(T& data);
    };
    template < class K, class T>
    class BalancedBinarySearchTree:BinarySearchTree<K, T>{
    public:
        T* get(K* key);
        bool insert(T& data);
        T* remove(T& data);
    };
    template < class K, class T >
    class AVLTree:BalancedBinarySearchTree<K,T>{
    public:
        T* get(K* key);
        bool insert(T& data);
        T* remove(T& data);
    };

}
#endif //CPPIMPL_TREE_STRUCTURE_H
