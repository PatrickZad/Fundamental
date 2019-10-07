//
// Created by pengcheng.zhang on 2019-08-07.
//

#ifndef CPPIMPL_PRIORITY_STRUCTURE_H
#define CPPIMPL_PRIORITY_STRUCTURE_H

#include "linear_structure.h"
namespace patrick{
    template <class K, class V>
    struct Item{
        K key;
        V value;
    };

    template <class K, class V>
    class Heap{
    public:
        Heap():length{0}{};
        unsigned int size();
        virtual void push(K& key, V& value)=0;
        virtual V pop()=0;
        virtual V& top()=0;
    protected:
        unsigned int length=0;
    };

    template <class K, class V>
    class ArrayHeap: public Heap<K,V>{
    private:
        ExtendableArray<Item<K,V>> array;
    public:
        void push(K& key, V& value);
        V pop();
        V& top();
    private:
        void maxHeapify(unsigned int index);
        Item<K,V>* parentOf(unsigned int index);
        Item<K,V>* leftOf(unsigned int index);
        Item<K,V>* rightOf(unsigned int index);
    };
/*
    template <class K, class V>
    struct HeapNode{
        K key;
        V value;
        HeapNode* parent;
        HeapNode* left;
        HeapNode* right;
    };

    template <class K, class V>
    class TreeHeap: public Heap<K,V>{
    private:
        HeapNode<K,V>* root;
    public:
        TreeHeap():root{nullptr},end{nullptr}{};
        ~TreeHeap();
        TreeHeap(const TreeHeap& heap);
        TreeHeap(TreeHeap&& heap);
        TreeHeap& operator=(const TreeHeap& heap);
        TreeHeap& operator=(TreeHeap&& heap);

        void push(K& key, V& value);
        V pop();
        V& top();

    };
    template <class K, class V>
    void releaseTree(HeapNode<K,V>* root);
    template <class K, class V>
    void copyTree(HeapNode<K,V>* destRoot,HeapNode<K,V>* sourRoot);
    */
    template <class K, class V>
    class PriorityQueue{
    private:
        unsigned int length;
        Heap<K,V> maxHeap;

    public:
        PriorityQueue():length{0},maxHeap{ArrayHeap<K,V>{}}{};
        unsigned int size();
        bool enqueue(K& key, V& value);
        V dequeue();

    };
}
#endif //CPPIMPL_PRIORITY_STRUCTURE_H
