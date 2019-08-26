//
// Created by pengcheng.zhang on 2019-07-24.
//
#include <utility>
#include "linear_structure.h"
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
T* ExtendableArray<T>::operator[](unsigned int index){
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
    this->stack=ExtendableArray<T>{stack};
    stack.stack=ExtendableArray<T>{};
    stack.length=0;
}

template <class T>
ArrayStack<T>& ArrayStack<T>::operator=(ArrayStack<T> &&stack) {
    //TODO
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
    this->list=ExtendableArray<T*>();
    this->length=0;
}
template <class T>
bool ArrayList<T>::insert(unsigned int index, T & element) {
    if(index>length){
        return false;
    }else
        if(index==length){
            list.append(&element);
            length+=1;
            return true;
        } else{
            list.append(list[length-1]);
            for (long i=length-2;i>index;i--){
                list[i+1]=list[i];
            }
            list[index]=&element;
            length+=1;
            return true;
        }
}
template <class T>
T* ArrayList<T>::remove(unsigned int index) {
    if (index>=length){
        return nullptr;
    }
    T* result=list[index];
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
T* ArrayList<T>::operator[](unsigned int index) {
    if(index>=length){
        return nullptr;
    }
    return list[index];
}
template <class T>
bool ArrayList<T>::append(T & element) {
    list.append(&element);
    length+=1;
}
template <class T>
LinkedList<T>::LinkedList() {
    length=0;
    BinaryNode<T> headnode=BinaryNode<T>{nullptr, nullptr, nullptr};
    head=&headnode;
}
template <class T>
T* LinkedList<T>::operator[](unsigned int index) {
    if(index>=length){
        return nullptr;
    }
    unsigned int count=0;
    LinkedNode<T>* nodep=head;
    while (count<index){
        nodep=nodep->next;
        count+=1;
    }
    return nodep;
}
template <class T>
unsigned int LinkedList<T>::size() {
    return length;
}
template <class T>
bool LinkedList<T>::insert(unsigned int index, T & element) {
    if (index>length){
        return false;
    }
    unsigned int count=0;
    LinkedNode<T>* nodep=head;
    while (count<index-1){
        nodep=nodep->next;
        count+=1;
    }
    LinkedNode<T> node=LinkedNode<T>{&element,nodep,nodep->next};
    nodep->next=&node;
    (node.next)->previous=&node;
    length+=1;
    return true;
}
template <class T>
bool LinkedList<T>::remove(unsigned int index) {
    if(index>=length){
        return false;
    }
    unsigned int count=0;
    LinkedNode<T>* nodep=head;
    while (count<index){
        nodep=nodep->next;
        count+=1;
    }
    nodep->previous->next=nodep->next;
    nodep->next->previous=nodep->previous;
    length-=1;
    return true;
}