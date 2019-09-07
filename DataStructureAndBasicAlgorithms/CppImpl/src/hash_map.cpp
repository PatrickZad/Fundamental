//
// Created by pengcheng.zhang on 2019/9/4.
//

#include "hash_map.h"
using namespace patrick;

/*
 * HashMap
 * */
template <class K, class V>
unsigned int HashMap<K,V>::size() {
    return length;
}

/*
 *LinkedHashMap
 * */
template <class K, class V>
LinkedHashMap<K,V>::LinkedHashMap(HashFunc<K>& func) {
    this->array=ExtendableArray<PairChain<K,V>>{};
    this->length=0;
    this->hashFunc=func;
}

template <class K, class V>
void LinkedHashMap<K,V>::add(K& key, V& value){

}

template <class K, class V>
V LinkedHashMap<K,V>::get(K& key){

}

template <class K, class V>
V LinkedHashMap<K,V>::remove(K& key){

}

template <class K, class V>
bool LinkedHashMap<K,V>::exists(K& key){

}