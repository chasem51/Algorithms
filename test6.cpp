#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <numeric>
#include <random>
#include <cstdlib>
#include "trie.h"
#include "MyBST.h"

void printVector(vector<int> inputVector){
    cout << "Vector: " << endl;
    for(int & i : inputVector){
        cout << i << " ";
    }
    cout << endl;
}

/*
void printRotationVector(vector<Rotation> inputVector){
    for(Rotation & i: inputVector){
        cout << i.print() << endl;
    }
    cout << endl;
}
*/

int main() {
    std::mt19937 gen(20200402);

    // (a)
    std::vector<int> nums(12);
    std::iota(nums.begin(), nums.end(), 1);
    std::shuffle(nums.begin(), nums.end(), gen);
    MyBST start(nums);
    std::shuffle(nums.begin(), nums.end(), gen);
    MyBST target(nums);
    std::cout << "START:\n * * *\n" << start.print();
    std::cout << "TARGET:\n * * *\n" << target.print();
    auto rotseq = start.transform(target);
    std::cout << "AFTER TRANSFORM:\n * * *\n" << start.print();

    // (b)
    
    Trie t;
    t.insert("hello", 12);
    t.insert("world", 19);
    t.insert("coffee", 12);
    t.insert("corinth", 99);
    std::cout << "map has " << t.map_size << " elements and " << t.tree_size << " nodes." << std::endl;
    std::cout << "hello: " << t.search("hello") << " (0 value means I don't have the key)" << std::endl;
    std::cout << "corinth: " << t.search("corinth") << " (0 value means I don't have the key)" << std::endl;
    std::cout << "lorem: " << t.search("lorem") << " (0 value means I don't have the key)" << std::endl;
    t.remove("corinth");
    std::cout << "REMOVE: corinth." << std::endl;
    std::cout << "hello: " << t.search("hello") << " (0 value means I don't have the key)" << std::endl;
    std::cout << "corinth: " << t.search("corinth") << " (0 value means I don't have the key)" << std::endl;
    std::cout << "map has " << t.map_size << " elements and " << t.tree_size << " nodes." << std::endl;
    

    return 0;
}