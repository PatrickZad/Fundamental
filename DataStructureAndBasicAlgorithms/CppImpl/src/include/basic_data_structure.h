//
// Created by pengcheng.zhang on 2019-07-24.
//

#ifndef CPPIMPL_BASIC_DATA_STRUCTURE_H
#define CPPIMPL_BASIC_DATA_STRUCTURE_H

#include <stdint.h>

namespace patrick{

    template <class T>
            struct Node{
            T data;
            Node<T>& next;
            };
    template <class T>
    class ArrayStack{
    public:
        ArrayStack();
        bool push(T);
        T pop();
        int size();
    private:
        const static u_int8_t N = 255;
        T stack[N];
        u_int8_t length=0;
    };
    template <class T>
    class ArrayQueue{
        /*
         * Circular Queue
         * */
    public:
        ArrayQueue();
        bool enqueue(T);
        T dequeue();
        int size();
    private:
        const static u_int8_t N = 255;
        T queue[N];
        u_int8_t length=0;
        u_int8_t front=0;
        u_int8_t next=0;
    };
    template <class T>
    class ArrayList{
    public:
        ArrayList();
        T get(int);
        bool set(int, T);
        bool insert(int, T);
        bool remove(int);
        int size();

    private:
        const static u_int8_t N = 255;
        T list[N];
        u_int8_t length=0;
    };
    template <class T>
    class LinkedList{
    public:
        LinkedList();
        T get(int);
        bool set(int, T);
        bool insert(int, T);
        bool remove(int);
        int size();

    private:
        int length=0;
        Node<T>& head;
    };
}
#endif //CPPIMPL_BASIC_DATA_STRUCTURE_H
