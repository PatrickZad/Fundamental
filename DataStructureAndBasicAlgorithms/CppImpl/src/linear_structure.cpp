//
// Created by pengcheng.zhang on 2019-07-24.
//

#include "linear_structure.h"
#include "exception.h"
using namespace patrick;
/*
 * ExtendableArray
 * */
template <class T>
ExtendableArray<T>::ExtendableArray() {
    this->length=0;
    this->repoSize=this->N;
    this->repo=new T[N];
}

template <class T>
ExtendableArray<T>::ExtendableArray(const ExtendableArray& array) {
    this->length=array.length;
    this->repoSize=array.repoSize;
    this->repo=new T[array.repoSize];
    for (unsigned int i=0;i<array.length;i++){
        (*this)[i]=array[i];
    }
}

template <class T>
ExtendableArray<T>::ExtendableArray(ExtendableArray<T> &&array) {
    this->length=array.length;
    this->repoSize=array.repoSize;
    this->repo=array.repo;
    array.repo= new T[array.N];
    array.length=0;
    array.repoSize=0;
}

template <class T>
ExtendableArray<T>::~ExtendableArray() {
    delete[] this->repo;
}

template <class T>
unsigned int ExtendableArray<T>::size() {
    return this->length;
}

template <class T>
void ExtendableArray<T>::append(T & element) {
    if(length==repoSize){
        T* previousRepo=this->repo;
        this->repo=new T[2*this->repoSize];
        for(unsigned int i=0;i<length;i++){
            repo[i]=previousRepo[i];
        }
        this->repo[length]=element;
        length+=1;
        delete [] previousRepo;
    } else
        if(length<repoSize){
        this->repo[length]=element;
        length+=1;
    }
}

template <class T>
bool ExtendableArray<T>::insert(unsigned int index,  T & element) {
    if (length==repoSize){
        T* previousRepo=this->repo;
        this->repo=new T[2*this->repoSize];
        for (unsigned int i =0;i<index;i++){
            repo[i]=previousRepo[i];
        }
        repo[index]=element;
        for (unsigned int i=index;i<length;i++){
            repo[i+1]=previousRepo[i];
        }
        delete [] previousRepo;
        length+=1;
        return true;
    } else
        if(length<repoSize){
        for (unsigned int i=length-1;i>=index;i--){
            repo[i+1]=repo[i];
        }
        repo[index]=element;
        return true;
    }
    throw OutofIndexException{};
}

template <class T>
T ExtendableArray<T>::remove(unsigned int index) {
    if(index<length){
        T result=this->repo[index];
        for (unsigned int i=index;i<length-1;i++){
            this->repo[i]=this->repo[i+1];
        }
        length--;
        return result;
    } else{
        throw OutofIndexException{};
    }
}

template <class T>
void ExtendableArray<T>::clear() {
    delete [] this->repo;
    this->repo=new T[this->N];
    this->length=0;
    this->repoSize=this->N;
}
template <class T>
T& ExtendableArray<T>::operator[](unsigned int index){
    if(index<length){
        return this->repo[index];
    } else{
        throw OutofIndexException{};
    }
}

template <class T>
ExtendableArray<T>& ExtendableArray<T>::operator=(const ExtendableArray<T> &array) {
    this->length=array.length;
    this->repoSize=array.repoSize;
    this->repo=new T[array.repoSize];
    for (unsigned int i=0;i<array.length;i++){
        *this[i]=array[i];
    }
    return *this;
}

template <class T>
ExtendableArray<T>& ExtendableArray<T>::operator=(ExtendableArray<T> &&array) {
    this->length=array.length;
    this->repoSize=array.repoSize;
    this->repo=array.repo;
    array.repo= new T[array.N];
    array.length=0;
    array.repoSize=0;
    return *this;
}

/*
 * ArrayStack
 * */
template <class T>
ArrayStack<T>::ArrayStack() {
    this->stack=ExtendableArray<T>{};
    this->length=0;
}

template <class T>
ArrayStack<T>::ArrayStack(ArrayStack<T> &&stack) {
    this->length=stack.length;
    this->stack=ExtendableArray<T>{stack.stack};
    stack.length=0;
}

template <class T>
ArrayStack<T>& ArrayStack<T>::operator=(ArrayStack<T> &&stack) {
    this->length=stack.length;
    this->stack=stack.stack;
    stack.length=0;
}

template <class T>
void ArrayStack<T>::push(T & element) {
    this->stack.append(element);
    length+=1;
}

template <class T>
T ArrayStack<T>::pop(){
    if(this->length==0){
        throw OutofIndexException{};
    } else{
        this->length-=1;
        return this->stack.remove(length);
    }
}

template <class T>
unsigned int ArrayStack<T>::size() {
    return this->length;
}

/*
 * ArrayQueue
 * */
template <class T>
ArrayQueue<T>::ArrayQueue() {
    this->length=0;
    this->front=0;
    this->next=0;
    this->queue=new T[this->N];
}

template <class T>
ArrayQueue<T>::ArrayQueue(const ArrayQueue& queue){
    this->queue=new T[this->N];
    if (front<next){
        for(int i=front;i<next;i++){
            (*this)[i]=queue[i];
        }
    } else{
        if (front>next){
            for (int i =front;i<this->N;i++){
                (*this)[i]=queue[i];
            }
            for (int i=0;i<next;i++){
                (*this)[i]=queue[i];
            }
        } else{
            if (queue.size()==this->N){
                for (int i=0;i<this->N;i++){
                    (*this)[i]=queue[i];
                }
            }
        }
    }
    this->length=queue.length;
    this->front=queue.front;
    this->next=queue.next;
}

template <class T>
ArrayQueue<T>::ArrayQueue(ArrayQueue&& queue){
    this->queue=queue.queue;
    queue.queue= new T[queue.N];
    this->length=queue.length;
    this->front=queue.front;
    this->next=queue.next;
    queue.length=0;
    queue.front=0;
    queue.next=0;
}

template <class T>
ArrayQueue<T>& ArrayQueue<T>::operator=(const ArrayQueue& queue){
    if (front<next){
        for(int i=front;i<next;i++){
            (*this)[i]=queue[i];
        }
    } else{
        if (front>next){
            for (int i =front;i<this->N;i++){
                (*this)[i]=queue[i];
            }
            for (int i=0;i<next;i++){
                (*this)[i]=queue[i];
            }
        } else{
            if (queue.size()==this->N){
                for (int i=0;i<this->N;i++){
                    (*this)[i]=queue[i];
                }
            }
        }
    }
    this->length=queue.length;
    this->front=queue.front;
    this->next=queue.next;
}

template <class T>
ArrayQueue<T>& ArrayQueue<T>::operator=(ArrayQueue&& queue){
    T* p=this->queue;
    this->queue=queue.queue;
    delete[] p;
    queue.queue= new T[queue.N];
    this->length=queue.length;
    this->front=queue.front;
    this->next=queue.next;
    queue.length=0;
    queue.front=0;
    queue.next=0;
}

template <class T>
ArrayQueue<T>::~ArrayQueue() {
    delete[] this->queue;
}

template <class T>
void ArrayQueue<T>::enqueue(T & element) {
    if(front==next && length==0){
        throw StorageOverflow{};
    }
    queue[next]=element;
    next=(next+1)%N;
    length+=1;
}
template <class T>
T ArrayQueue<T>::dequeue() {
    if(length==0){
        throw NullContainer{};
    }
    T result=queue[front];
    length-=1;
    front=(front+1)%N;
    return result;
}
template <class T>
unsigned int ArrayQueue<T>::size() {
    return length;
}

/*
 * ArrayList
 * */
template <class T>
ArrayList<T>::ArrayList() {
    this->list=ExtendableArray<T>{};
    this->length=0;
}

template <class T>
ArrayList<T>::ArrayList(ArrayList &&list) {
    this->length=list.length;
    this->list=ExtendableArray<T>{list.list};
    list.length=0;
}

template < class T>
ArrayList<T>& ArrayList<T>::operator=(ArrayList<T> &&list) {
    this->length=list.length;
    this->list=list.list;
    list.length=0;
}

template <class T>
void ArrayList<T>::insert(unsigned int index, T & element) {
    if(index>length){
        throw OutofIndexException{};
    }else
        if(index==length){
            list.append(element);
            length+=1;
        } else{
            list.append(list[length-1]);
            for (long i=length-2;i>index;i--){
                list[i+1]=list[i];
            }
            list[index]=element;
            length+=1;
        }
}
template <class T>
T ArrayList<T>::remove(unsigned int index) {
    if (index>=length){
        throw OutofIndexException{};
    }
    T result=list[index];
    for (unsigned int i =index+1;i<length;i++){
        list[i-1]=list[i];
    }
    length-=1;
    return result;
}
template <class T>
unsigned int ArrayList<T>::size() {
    return length;
}
template <class T>
T& ArrayList<T>::operator[](unsigned int index) {
    if(index>=length){
        throw OutofIndexException{};
    }
    return list[index];
}
template <class T>
void ArrayList<T>::append(T & element) {
    list.append(element);
    length+=1;
}

/*
 * LinkedList
 * */
template <class T>
LinkedList<T>::LinkedList() {
    length=0;
    head= nullptr;
}

template <class T>
void LinkedList<T>::releaseRecursivly(LinkedNode<T> *node) {
    if(node == nullptr){
        return;
    }
    releaseRecursivly(node->next);
    node->previous->next= nullptr;
    delete node;
}

template <class T>
LinkedList<T>::~LinkedList() {
    length=0;
    this->releaseRecursivly(this->head);
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList& list){
    head=new LinkedNode<T>{list.head->data, nullptr, nullptr};
    LinkedNode<T>* pre=head;
    LinkedNode<T>* sourcenode=list.head->next;
    for (unsigned int i=1;i<list.length;i++){
        LinkedNode<T>* node=new LinkedNode<T>{sourcenode->data,pre, nullptr};
        pre->next=node;
        pre=node;
        sourcenode=sourcenode->next;
    }
    this->length=list.length;
}

template <class T>
LinkedList<T>::LinkedList(LinkedList&& list){
    this->head=list.head;
    this->length=list.length;
    list.head= nullptr;
    list.length=0;
}

template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& list){
    releaseRecursivly(head);
    head=new LinkedNode<T>{list.head->data, nullptr, nullptr};
    LinkedNode<T>* pre=head;
    LinkedNode<T>* sourcenode=list.head->next;
    for (unsigned int i=1;i<list.length;i++){
        LinkedNode<T>* node=new LinkedNode<T>{sourcenode->data,pre, nullptr};
        pre->next=node;
        pre=node;
        sourcenode=sourcenode->next;
    }
    this->length=list.length;
}

template <class T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList&& list){
    releaseRecursivly(head);
    this->head=list.head;
    this->length=list.length;
    list.head= nullptr;
    list.length=0;
}

template <class T>
T& LinkedList<T>::operator[](unsigned int index) {
    if(index>=length){
        throw OutofIndexException{};
    }
    unsigned int count=0;
    LinkedNode<T>* nodep=head;
    while (count<index){
        nodep=nodep->next;
        count+=1;
    }
    return nodep->data;
}
template <class T>
unsigned int LinkedList<T>::size() {
    return length;
}

template <class T>
void LinkedList<T>::insert(unsigned int index, T & element) {
    if (index>length){
        throw OutofIndexException{};
    }
    unsigned int count=0;
    LinkedNode<T>* nodep=head;
    while (count<index-1){
        nodep=nodep->next;
        count+=1;
    }
    LinkedNode<T>* node=new LinkedNode<T>{&element,nodep,nodep->next};
    nodep->next=node;
    (node->next)->previous=node;
    length+=1;
}

template <class T>
T LinkedList<T>::remove(unsigned int index) {
    if(index>=length){
        throw OutofIndexException{};
    }
    unsigned int count=0;
    LinkedNode<T>* nodep=head;
    while (count<index){
        nodep=nodep->next;
        count+=1;
    }
    nodep->previous->next=nodep->next;
    nodep->next->previous=nodep->previous;
    T result=nodep->data;
    delete nodep;
    length-=1;
    return result;
}

template <class T>
void LinkedList<T>::append(T &data){
    if (this->length==0){
        this->head=new LinkedNode<T>{data, nullptr, nullptr};
        return;
    }
    LinkedNode<T>* pre=this->head;
    while (pre->next!= nullptr){
        pre=pre->next;
    }
    pre->next=new LinkedNode<T>{data,pre, nullptr};
}