//
// Created by pengcheng.zhang on 2019-08-07.
//

#ifndef CPPIMPL_KV_STRUCTURE_H
#define CPPIMPL_KV_STRUCTURE_H
namespace patrick{
    template <class K, class V>
    struct item{
        K key;
        V value;
    };
    template <class K, class V>
    class PriorityQueue{
    public:
        PriorityQueue();
        unsigned int size();
        bool enqueue(K key, V value);
        V* dequeue();
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
        unsigned int height(K key);
        unsigned int depth(K key);
        void insert(K key, V value);
    private:
        unsigned int length;
    };
}
#endif //CPPIMPL_KV_STRUCTURE_H
