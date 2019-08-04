//
// Created by pengcheng.zhang on 2019-07-24.
//

#ifndef CPPIMPL_BASIC_DATA_STRUCTURE_H
#define CPPIMPL_BASIC_DATA_STRUCTURE_H


namespace patrick{


    template <class T>
    class ExtendableArray{
    public:
        ExtendableArray();
        unsigned int size();
        bool add(T&);
        bool insert(unsigned int ,T&);
        T& get(unsigned int);
        bool remove(unsigned int);
        bool clear();
        T& operator[](unsigned int);
        ~ExtendableArray();
    private:
        static const unsigned int N=64;
        unsigned int repoSize=N;
        unsigned int length=0;
        T* repo=new T[N];
    };
    template <class T>
    class ArrayStack{
    public:
        ArrayStack();
        bool push(T&);
        T& pop();
        unsigned int size();
        ~ArrayStack();
    private:
        const static unsigned int N = 255;
        T* stack=new T[N];
        unsigned int length=0;
    };
    template <class T>
    class ArrayQueue{
        /*
         * Circular Queue
         * */
    public:
        ArrayQueue();
        bool enqueue(T&);
        T& dequeue();
        unsigned int size();
        ~ArrayQueue();
    private:
        const static unsigned int N = 255;
        T* queue=new T[N];
        unsigned int length=0;
        unsigned int front=0;
        unsigned int next=0;
    };
    template <class T>
    class ArrayList{
    public:
        ArrayList();
        T& get(unsigned int);
        bool insert(unsigned int, T&);
        bool remove(unsigned int);
        unsigned int size();
        T& operator[](unsigned int);
        ~ArrayList();
    private:
        const static unsigned int N = 255;
        T* list=new T[N];
        unsigned int length=0;
    };

    template <class T>
    struct LinkedNode{
        T* data;
        LinkedNode<T>* previous;
        LinkedNode<T>* next;
    };

    template <class T>
    class LinkedList{
    public:
        LinkedList();
        T& get(unsigned int);
        bool insert(unsigned int, T&);
        bool remove(unsigned int);
        unsigned int size();
        T& operator[](unsigned int);
    private:
        unsigned int length=0;
        LinkedNode<T>& head;
    };
    template <class T>
    struct BinaryNode{
        T* data;
        BinaryNode<T>* left;
        BinaryNode<T>* right;
    };
    template <class T>
    class BinaryTree{
    public:
        BinaryTree();
        BinaryNode<T>& parent(BinaryNode<T>&);
        unsigned int size();
    private:
        BinaryNode<T>* root;
    };

}
#endif //CPPIMPL_BASIC_DATA_STRUCTURE_H
