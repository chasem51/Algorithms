#ifndef __TRIE_H__
#define __TRIE_H__

#include <string>

using namespace std;

const int ALPHABET_SIZE = 26; // Consider only lowercase letters for this problem

struct TrieNode {
    TrieNode *children[ALPHABET_SIZE];
    int val;
    TrieNode() {
        val = 0; // Default
        for (int i=0; i<ALPHABET_SIZE; i++) {
            children[i] = NULL;
        }
    }
};

class Trie {

public:
    TrieNode *root;
    int map_size; // size of the map
    int tree_size; // size of the tree
    Trie() {
        root = new TrieNode();
        map_size = 0;
        tree_size = 1;
    }

    /*
       Insert (key, val) into the trie. If key is already present, update the corresponding value.
       Update map_size and tree_size accordingly. If key is already present, these numbers should not change.
       */
    void insert(string key, int val);

    /*
       Search key and return the corresponding value. Return 0 if key is not present in the trie.
       */
    int search(string key);

    /*
       Remove key from the trie. Update map_size and tree_size accordingly.
       If the node corresponding to the key is a leaf node, you should remove the node.
       If the node corresponding to the key is not a leaf node, you should update its value accordingly but should not remove the node.
       */
    void remove(string key);
};
#endif