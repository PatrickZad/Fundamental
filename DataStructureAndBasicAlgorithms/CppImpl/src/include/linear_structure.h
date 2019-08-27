//
// Created by pengcheng.zhang on 2019-07-24.
//

#ifndef CPPIMPL_LINEAR_STRUCTURE_H
#define CPPIMPL_LINEAR_STRUCTURE_H


namespace patrick{
//Element will be copied to these collections.
    template <class T>
    class ExtendableArray{
    public:
        ExtendableArray();
        ExtendableArray(const ExtendableArray& array);
        ExtendableArray(ExtendableArray&& array);
        ~ExtendableArray();
        unsigned int size();
        void append(T&);
        bool insert(unsigned int ,T&);
        T remove(unsigned int);
        void clear();
        T& operator[](unsigned int);
        ExtendableArray& operator=(const ExtendableArray& array);
        ExtendableArray& operator=(ExtendableArray&& array);
    private:
        static const unsigned int N=64;
        unsigned int repoSize;
        unsigned int length;
        T* repo;
    };

    template <class T>
    class ArrayStack{
    public:
        ArrayStack();
        ArrayStack(ArrayStack&& stack);
        ArrayStack& operator=(ArrayStack&& stack);
        void push(T&);
        T pop();
        unsigned int size();

    private:
        ExtendableArray<T> stack;
        unsigned int length;
    };

    template <class T>
    class ArrayQueue{
        /*
         * Circular Queue
         * */
    public:
        ArrayQueue();
        ArrayQueue(const ArrayQueue& queue);
        ArrayQueue(ArrayQueue&& queue);
        ~ArrayQueue();
        ArrayQueue& operator=(const ArrayQueue& queue);
        ArrayQueue& operator=(ArrayQueue&& queue);
        void enqueue(T&);
        T dequeue();
        unsigned int size();
    private:
        const static unsigned int N = 256;
        T* queue;
        unsigned int length;
        unsigned int front;
        unsigned int next;
    };

    template <class T>
    class ArrayList{
    public:
        ArrayList();
        ArrayList(ArrayList&& list);
        ArrayList& operator=(ArrayList&& list);
        void insert(unsigned int index, T& data);
        T remove(unsigned int index);
        unsigned int size();
        T& operator[](unsigned int);
        void append(T&);
    private:
        ExtendableArray<T> list;
        unsigned int length;
    };

    template <class T>
    struct LinkedNode{
        T data;
        LinkedNode<T>* previous;
        LinkedNode<T>* next;
    };

    template <class T>
    class LinkedList{
    public:
        LinkedList();
        LinkedList(const LinkedList& list);
        LinkedList(LinkedList&& list);
        ~LinkedList();
        LinkedList& operator=(const LinkedList& list);
        LinkedList& operator=(LinkedList&& list);
        void insert(unsigned int, T&);
        T remove(unsigned int);
        void append(T& data);
        unsigned int size();
        T& operator[](unsigned int);
    private:
        unsigned int length;
        LinkedNode<T>* head;
        void releaseRecursivly(LinkedNode<T>* node);
    };

    class OutofIndexException{};
    class StorageOverflow{};
    class NullContainer{};
}
#endif //CPPIMPL_LINEAR_STRUCTURE_H
