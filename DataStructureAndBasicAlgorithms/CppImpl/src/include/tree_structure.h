//
// Created by pengcheng.zhang on 2019-08-07.
//

#ifndef CPPIMPL_TREE_STRUCTURE_H
#define CPPIMPL_TREE_STRUCTURE_H
namespace patrick{
    static const char PREORDER_THREADED=0;
    static const char INORDER_THREADED=1;
    static const char POSTORDER_THREADED=2;
    template <class T>
    struct BinaryNode{
        T* data;
        BinaryNode* left;
        BinaryNode* right;
    };
    template <class T>
    class BinaryTree{
    public:
        BinaryTree();
        BinaryTree(T* data);
        unsigned int size();
        virtual BinaryNode<T>* search(T& data)=0;
        virtual bool insert(T& data)=0;
        virtual bool remove(T& data)=0;
        BinaryNode<T>* head;
        static const char PREORDER_THREADED=0;
        static const char INORDER_THREADED=1;
        static const char POSTORDER_THREADED=2;
        void threaded(char order);
        BinaryNode<T>* getRoot();
    private:
        unsigned int length;
        BinaryNode<T> root;
    };
    template < class T,class F>
    void preOrderTraversal(BinaryNode<T>& root,F& visitFunc);
    template <class T, class F>
    void preOrderTraversalStacking(BinaryTree<T>& tree,F& visitFunc);

    template < class T, class F>
    void inOrderTraversal(BinaryNode<T>& root,F& visitFunc);
    template <class T, class F>
    void inOrderTraversalStacking(BinaryTree<T>& tree,F& visitFunc);
    template < class T, class F>
    void postOrderTraversal(BinaryNode<T>& root,F& visitFunc);
    template <class T, class F>
    void postOrderTraversalStacking(BinaryTree<T>& tree, F& visitFunc);
    template < class T, class F>
    void layerTraversal(BinaryTree<T>& tree, F& visitFunc);
    template <class T>
    class BinarySearchTree:BinaryTree<T>{
    public:
        T* get(unsigned int index);
        bool insert(T& data);
        T* remove(T& data);
    };
    template <class T>
    class BalancedBinarySearchTree:BinarySearchTree<T>{
    public:
        T* get(unsigned int index);
        bool insert(T& data);
        T* remove(T& data);
    };

}
#endif //CPPIMPL_TREE_STRUCTURE_H
