//
// Created by pengcheng.zhang on 2019-08-07.
//
#include "priority_structure.h"
#include "exception.h"
using namespace patrick;

/*
 * Heap
 * */
template <class K, class V>
unsigned int Heap<K,V>::size() {
    return length;
}

/*
 * ArrayHeap
 * */
template <class K, class V>
void ArrayHeap<K,V>::push(K &key, V &value) {
    Item<K,V> item{key,value};
    array.append(item);
    this->length++;
    unsigned int indexOfItem=this->length-1;
    //down to top
    while (parentOf(indexOfItem)!= nullptr && key>parentOf(indexOfItem)->key){
        auto temp=*parentOf(indexOfItem);
        *parentOf(indexOfItem)=array[indexOfItem];
        array[indexOfItem]=temp;
    }
}

template <class K, class V>
V ArrayHeap<K,V>::pop() {
    if (this->length==0){
        throw OutofIndexException{};
    }
    auto result=array[0];
    array[0]=array[this->length-1];
    this->length--;
    //top to down
    maxHeapify(0);
    return result;
}

template <class K, class V>
V& ArrayHeap<K,V>::top() {
    if (this->length==0){
        throw OutofIndexException{};
    }
    return array[0].value;
}

template <class K, class V>
void ArrayHeap<K,V>::maxHeapify(unsigned int index) {
    unsigned int largest=index;
    unsigned int left=index*2+1;
    unsigned int right=2*(index+1);
    if (left<this->length && array[left].key>array[index].key){
        largest=left;
    }
    if (right<this->length && array[right].key>array[largest].key){
        largest=right;
    }
    if (largest!=index){
        auto temp=array[index];
        array[index]=array[largest];
        array[largest]=temp;
        maxHeapify(largest);
    }
}

template <class K, class V>
Item<K,V>* ArrayHeap<K,V>::parentOf(unsigned int index) {
    if (index >= this->length){
        throw OutofIndexException{};
    }
    if (index == 0){
        return nullptr;
    }
    return &array[(index-1)/2];
}

template <class K, class V>
Item<K,V>* ArrayHeap<K,V>::leftOf(unsigned int index) {
    if (index >= this->length){
        throw OutofIndexException{};
    }
    unsigned int leftIndex=index*2+1;
    if (leftIndex>=this->length){
        return nullptr;
    }
    return &array[leftIndex];
}

template <class K, class V>
Item<K,V>* ArrayHeap<K,V>::rightOf(unsigned int index) {
    if (index >= this->length){
        throw OutofIndexException{};
    }
    unsigned int rightIndex=(index+1)*2;
    if (rightIndex>=this->length){
        return nullptr;
    }
    return &array[rightIndex];
}
/*
template <class K, class V>
TreeHeap<K,V>::~TreeHeap() {
    releaseTree(root);
}

template <class K, class V>
TreeHeap<K,V>::TreeHeap(const TreeHeap<K, V> &heap) {
    this->root=new HeapNode<K,V>{heap.root->key,heap.root->value, nullptr, nullptr, nullptr};
    copyTree(this->root,heap.root);
}

template <class K, class V>
TreeHeap<K,V>::TreeHeap(TreeHeap<K, V> &&heap) {
    this->root=heap.root;
    this->length=heap.length;
    heap.root= nullptr;
    heap.length=0;
}

template <class K, class V>
TreeHeap<K,V>& TreeHeap<K,V>::operator=(const TreeHeap<K, V> &heap) {
    releaseTree(this->root);
    copyTree(this->root,heap.root);
    this->length=heap.length;
}

template <class K, class V>
TreeHeap<K,V>& TreeHeap<K,V>::operator=(TreeHeap<K, V> &&heap) {
    releaseTree(this->root);
    this->root=heap.root;
    this->length=heap.length;
    heap.root= nullptr;
    heap.length=0;
}

template <class K, class V>
void TreeHeap<K,V>::push(K &key, V &value) {

}
 */

/*
 * PriorityQueue based on ArrayHeap
 * */
template <class K, class V>
unsigned int PriorityQueue<K,V>::size() {
    return this->length;
}

template <class K, class V>
bool PriorityQueue<K,V>::enqueue(K &key, V &value) {
    maxHeap.push(key,value);
}

template <class K, class V>
V PriorityQueue<K,V>::dequeue() {
    return maxHeap.pop();
}

