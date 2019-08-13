//
// Created by pengcheng.zhang on 2019-07-24.
//

#ifndef CPPIMPL_LINEAR_STRUCTURE_H
#define CPPIMPL_LINEAR_STRUCTURE_H


namespace patrick{
//Only element pointer will be saved in these collections,
//for which only element reference needs to be conveyed
//and template type should be specified as the type of elements itself,
//not its reference.
    template <class T>
    class ExtendableArray{
    public:
        ExtendableArray();
        ~ExtendableArray();
        unsigned int size();
        bool append(T&);
        bool insert(unsigned int ,T&);
        T* remove(unsigned int);
        void clear();
        T* operator[](unsigned int);
    private:
        static const unsigned int N=64;
        unsigned int repoSize;
        unsigned int length;
        T** repo;
    };
    template <class T>
    class ArrayStack{
    public:
        ArrayStack();
        void push(T&);
        T* pop();
        unsigned int size();
        //~ArrayStack();
    private:
        //const static unsigned int N = 255;
        ExtendableArray<T*> stack;
        unsigned int length;
    };
    template <class T>
    class ArrayQueue{
        /*
         * Circular Queue
         * */
    public:
        ArrayQueue();
        bool enqueue(T&);
        T* dequeue();
        unsigned int size();
        ~ArrayQueue();
    private:
        const static unsigned int N = 255;
        T** queue;
        unsigned int length;
        unsigned int front;
        unsigned int next;
    };
    template <class T>
    class ArrayList{
    public:
        ArrayList();
        bool insert(unsigned int, T&);
        T* remove(unsigned int);
        unsigned int size();
        T* operator[](unsigned int);
        bool append(T&);
        //~ArrayList();
    private:
        //const static unsigned int N = 255;
        ExtendableArray<T*> list;
        unsigned int length;
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
        bool insert(unsigned int, T&);
        bool remove(unsigned int);
        unsigned int size();
        T* operator[](unsigned int);
    private:
        unsigned int length;
        LinkedNode<T>* head;
    };
}
#endif //CPPIMPL_LINEAR_STRUCTURE_H
