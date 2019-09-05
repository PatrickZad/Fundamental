//
// Created by pengcheng.zhang on 2019/9/4.
//

#ifndef CPPIMPL_HASH_MAP_H
#define CPPIMPL_HASH_MAP_H

#include "linear_structure.h"
namespace patrick{

template <class K, class V>
struct Pair{
    K key;
    V value;
};

template <class K, class V>
class HashMap{
public:
    virtual void add(K& key, V& value)=0;
    virtual V get(K& key)=0;
    virtual V remove(K& key);
    virtual bool exists(K& key);
};

template <class K, class V>
struct PairChain{
    Pair<K,V>* self;
    Pair<K,V>* next;
};
template <class K, class V>
class LinkedHashMap{
public:
    LinkedHashMap();
    ~LinkedHashMap();
    LinkedHashMap(const LinkedHashMap& map);
    LinkedHashMap(LinkedHashMap&& map);
    LinkedHashMap& operator=(const LinkedHashMap& map);
    LinkedHashMap& operator=(LinkedHashMap&& map);

private:
    patrick::ExtendableArray<PairChain<K,V>> array;
};

template <class K, class V>
class OpenAddressingHashMap{
public:
    OpenAddressingHashMap();
    ~OpenAddressingHashMap();
    OpenAddressingHashMap& operator=(const OpenAddressingHashMap& map);
    OpenAddressingHashMap& operator=(OpenAddressingHashMap&& map);

private:
    patrick::ExtendableArray<Pair<K,V>*> array;
};

}
#endif //CPPIMPL_HASH_MAP_H
