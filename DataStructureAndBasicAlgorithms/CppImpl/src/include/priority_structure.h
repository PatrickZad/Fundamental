//
// Created by pengcheng.zhang on 2019-08-07.
//

#ifndef CPPIMPL_PRIORITY_STRUCTURE_H
#define CPPIMPL_PRIORITY_STRUCTURE_H
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
    };
}
#endif //CPPIMPL_PRIORITY_STRUCTURE_H
