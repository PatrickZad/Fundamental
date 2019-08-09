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
        BinaryNode<T>* head;
        template < class F>
        void preOrderTraversal(F& visitFunc);
        template < class F>
        void inOrderTraversal(F& visitFunc);
        template < class F>
        void postOrderTraversal(F& visitFunc);
        template < class F>
        void layerTraversal(F& visitFunc);
    private:
        unsigned int length;
    };

}
#endif //CPPIMPL_TREE_STRUCTURE_H
