//
// Created by pengcheng.zhang on 2019/9/4.
//

#ifndef CPPIMPL_HASH_MAP_H
#define CPPIMPL_HASH_MAP_H

#include "linear_structure.h"
namespace patrick{

    //Hash Functions
    template <class K>
    class HashFunc{
    public:
        virtual unsigned int operator()(K& key)=0;
    };

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
        unsigned int size();
    private:
        unsigned int length;
        HashFunc<K> hashFunc;
    };

    template <class K, class V>
    struct PairChain{
        Pair<K,V>* self;
        Pair<K,V>* next;
    };
    template <class K, class V>
    class LinkedHashMap:HashMap<K,V>{
    public:
        LinkedHashMap(HashFunc<K>& func);
        void add(K& key, V& value);
        V get(K& key);
        V remove(K& key);
        bool exists(K& key);
    private:
        patrick::ExtendableArray<PairChain<K,V>> array;
    };

    template <class K, class V>
    class OpenAddressingHashMap:HashMap<K,V>{
    public:
        OpenAddressingHashMap();
        ~OpenAddressingHashMap();
        OpenAddressingHashMap& operator=(const OpenAddressingHashMap& map);
        OpenAddressingHashMap& operator=(OpenAddressingHashMap&& map);
        void add(K& key, V& value);
        V get(K& key);
        V remove(K& key);
        bool exists(K& key);
    private:
        patrick::ExtendableArray<Pair<K,V>*> array;
    };


}
#endif //CPPIMPL_HASH_MAP_H
