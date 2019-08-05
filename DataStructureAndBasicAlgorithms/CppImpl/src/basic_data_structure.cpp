//
// Created by pengcheng.zhang on 2019-07-24.
//
#include "basic_data_structure.h"
using namespace patrick;
template <class T>
ExtendableArray<T>::ExtendableArray() {
    this->length=0;
    this->repoSize=this->N;
    this->repo=new T[N];
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
bool ExtendableArray<T>::append(T & element) {
    if(length==repoSize){
        T** previousRepo=this->repo;
        this->repo=new T*[2*this->repoSize];
        for(unsigned int i=0;i<length;i++){
            repo[i]=previousRepo[i];
        }
        this->repo[length]=&element;
        length+=1;
        delete [] previousRepo;
        return true;
    } else
        if(length<repoSize){
        this->repo[length]=&element;
        length+=1;
        return true;
    }
    return false;
}
template <class T>
bool ExtendableArray<T>::insert(unsigned int index,  T & element) {
    if (length==repoSize){
        T** previousRepo=this->repo;
        this->repo=new T*[2*this->repoSize];
        for (unsigned int i =0;i<index;i++){
            repo[i]=previousRepo[i];
        }
        repo[index]=&element;
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
        repo[index]=&element;
        return true;
    }
    return false;
}
template <class T>
T* ExtendableArray<T>::remove(unsigned int index) {
    if(index<length){
        T* result=this->repo[index];
        for (unsigned int i=index;i<length-1;i++){
            this->repo[i]=this->repo[i+1];
        }
        this->repo[length-1]= nullptr;
        return result;
    }
    return nullptr;
}
template <class T>
void ExtendableArray<T>::clear() {
    delete [] this->repo;
    this->repo=new T*[this->N];
}
template <class T>
T* ExtendableArray<T>::operator[](unsigned int index){
    if(index<length){
        return this->repo[index];
    } else{
        return nullptr;
    }
}
template <class T>
ArrayStack<T>::ArrayStack() {
    this->stack=ExtendableArray<T*>();
    this->length=0;
}
template <class T>
void ArrayStack<T>::push(T & element) {
    this->stack.append(element);
    length+=1;
}
template <class T>
T* ArrayStack<T>::pop(){
    if(this->length==0){
        return nullptr;
    } else{
        this->length-=1;
        return this->stack[length-1];
    }
}
template <class T>
unsigned int ArrayStack<T>::size() {
    return this->length;
}
template <class T>
ArrayQueue<T>::ArrayQueue() {
    this->length=0;
    this->front=0;
    this->next=0;
    this->queue=new T*[this->N];
}
template <class T>
ArrayQueue<T>::~ArrayQueue() {
    delete[] this->queue;
}
template <class T>
bool ArrayQueue<T>::enqueue(T & element) {
    if(front==next && length==0){
        return false;
    }
    queue[next]=&element;
    next=(next+1)%N;
    length+=1;
    return true;
}
template <class T>
T* ArrayQueue<T>::dequeue() {
    if(length==0){
        return nullptr;
    }
    T* result=queue[front];
    length-=1;
    front=(front+1)%N;
    return result;
}
template <class T>
unsigned int ArrayQueue<T>::size() {
    return length;
}
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