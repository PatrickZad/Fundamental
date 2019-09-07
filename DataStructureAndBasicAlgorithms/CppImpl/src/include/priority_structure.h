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
    class PriorityQueue{
    public:
        PriorityQueue();
        unsigned int size();
        bool enqueue(K& key, V& value);
        Item<K,V> dequeue();
    private:
        unsigned int length;
    };
    template <class K, class V>
    struct HeapNode{
        K key;
        V value;
        HeapNode* left;
        HeapNode* right;
    };

    template <class K, class V>
    class Heap{
    public:
        Heap();
        unsigned int size();
        virtual unsigned int height(K& key)=0;
        virtual unsigned int depth(K& key)=0;
        virtual void insert(K& key, V& value)=0;
        virtual void remove(K& key)=0;
    private:
        unsigned int length;
    };

    template <class K, class V>
    class ArrayHeap:Heap<K,V>{
    public:
        void insert(K& key, V& value);
        Item<K,V> remove(K& key);
        unsigned int height(K& key);
        unsigned int depth(K& key);
    private:
        ExtendableArray<Item<K,V>> array;
        unsigned int parentIndexOf(unsigned int index);
        unsigned int leftIndexOf(unsigned int index);
        unsigned int rightIndexOf(unsigned int index);
    };

    template <class K, class V>
    class TreeHeap:Heap<K,V>{
    public:
        TreeHeap();
        ~TreeHeap();
        TreeHeap(const TreeHeap& heap);
        TreeHeap(TreeHeap&& heap);
        TreeHeap& operator=(const TreeHeap& heap);
        TreeHeap& operator=(TreeHeap&& heap);
        void insert(K& key, V& value);
        Item<K,V> remove(K& key);
        unsigned int height(K& key);
        unsigned int depth(K& key);

    private:
        HeapNode<K,V>* root;
    };
}
#endif //CPPIMPL_PRIORITY_STRUCTURE_H
