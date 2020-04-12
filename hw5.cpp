// Chase Maivald
// U18719879

#include <iostream>
#include <math.h>
#include <algorithm>
#include "hw5.h"

using namespace std; 

std::vector<int> findMinK(const int k, const std::vector<int>& small_min_heap){
    std::vector<int> foo;
    for(int i = 0;i<k;i++){
        foo.push_back(small_min_heap[i]);
    }
    for(int i=1;i<k;i++){
        for(int j = k;j<small_min_heap.size();j++){
            if(foo[i] > small_min_heap[j]){
                foo[i] = small_min_heap[j];
            }
        }
    }

    for(int i=1;i<k;i++){
        for(int j=i;j<k;j++){
            if(foo[i] > foo[j]){
                swap(foo[i],foo[j]);
            }
        }
    }

    return foo;
}

class DJBHash : public HashFun {
    unsigned int operator()(const std::string& key) {
        unsigned int hash = 5381;
        unsigned int i = 0;

        for (std::size_t i = 0; i < key.length(); i++){            
            hash = ((hash << 5) + hash) + key[i];    
        }
        return (hash & 0x7FFFFFFF);
    }
};

class JSHash : public HashFun {
    unsigned int operator()(const std::string& key) {
        unsigned int hash = 5;

        for (std::size_t i = 0; i < key.length(); i++)
        {
            hash ^= ((hash << 5) + key[i] + (hash >> 2));
        }
        return (hash & 0x7FFFFFFF);
    }
};

void BloomFilter::add_hash_funs(){

    DJBHash* h1 = new DJBHash();
    JSHash* h2 = new JSHash();
    this->hash_funs.push_back(h1);
    this->hash_funs.push_back(h2);

}

void BloomFilter::insert(const std::string& key){

    for (int i = 0; i < hash_funs.size(); i++){
        int hash_result = this->call_hash(i, key) % 330;
        int same = hash_result;
        (this->filter)[hash_result] = 1;
    }
}

bool BloomFilter::member(const std::string& key){

    bool in = true;
    for (int i = 0; i < hash_funs.size(); i++){
        int hash_result = this->call_hash(i, key) % 330;
        if ((this->filter)[hash_result] == 0){
            in = false;
        }
    }
    if(in == true){
        return true;
    }
    else{
        return false;
    }
}

