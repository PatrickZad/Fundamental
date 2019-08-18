//
// Created by pengcheng.zhang on 2019-08-07.
//

#ifndef CPPIMPL_TREE_STRUCTURE_H
#define CPPIMPL_TREE_STRUCTURE_H
namespace patrick{
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
        unsigned int size();
        virtual T* get(unsigned int index)=0;
        virtual bool insert(T& data)=0;
        virtual T* remove(T& data)=0;
        BinaryNode<T>* head;
        static const char PREORDER_THREADED=0;
        static const char INORDER_THREADED=1;
        static const char POSTORDER_THREADED=2;
        void threaded(char order);
    private:
        unsigned int length;
    };
    template < class T,class F>
    void preOrderTraversal(BinaryNode<T>& root,F& visitFunc);
    template < class T, class F>
    void inOrderTraversal(BinaryNode<T>& root,F& visitFunc);
    template < class T, class F>
    void postOrderTraversal(BinaryNode<T>& root,F& visitFunc);
    template < class T, class F>
    void layerTraversal(BinaryNode<T>& root, F& visitFunc);
    template <class T>
    class BinarySearchTree:BinaryTree<T>{

    };

}
#endif //CPPIMPL_TREE_STRUCTURE_H
