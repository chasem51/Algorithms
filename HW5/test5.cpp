#include <iostream>
#include <vector>
#include "hw5.h"

int main() {
    std::vector<int> small_min_heap = { 10, 14, 19, 26, 31, 42, 27, 44, 35, 33};
    std::vector<int> smallest_3 = findMinK(7, small_min_heap);
    std::cout << "smallest 3 elements are: ";
    // should print 0, 1, 2, in any order.
    for (auto it = smallest_3.begin(); it != smallest_3.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    
    BloomFilter bf = BloomFilter();
    bf.insert("Hello, World!");
    bf.insert("Lorem ipsum");

    std::cout << (bf.member("foo bar") ?
            "'foo bar' is in our bloom filter" :
            "'foo bar' is not in our bloom filter")
        << std::endl;
    
    
    return 0;
}