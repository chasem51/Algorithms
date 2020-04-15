// LATE DAY
// Chase Maivald
// U18719879

#include <string>
#include "trie.h"

using namespace std;

void Trie::insert(string key, int val) {

    TrieNode* temp = root;

    for(int i = 0; i < key.length(); i++){
        if(temp->children[key[i] - 'a'] == NULL){ // if the respective indice to a character DNE,
            temp->children[key[i] - 'a'] = new TrieNode(); // init a new node for the trie map
            tree_size++; // inc the tree size for every appended character
        }

        temp = temp->children[key[i] - 'a'] ; // place temp at the new indice
    }

    temp->val = val;
    map_size++; // inc the map size for every new val


}

int Trie::search(string key) {
    TrieNode *temp = root; // start at root

    for (int i = 0; i < key.length(); i++){
        if (temp->children[key[i] - 'a'] == NULL){ // if the respective indice's val in array of ptrs DNE
            return 0;
        }
        temp = temp->children[key[i] - 'a']; // place temp at the string's respective indice
    }

    return temp->val; // return the value for the string character
}

// 1 if the string's char has no children
bool isLeaf(TrieNode* node){
    for (int i = 0; i < 26; i++){
        if ((node->children[i]) != NULL){
            return 0;
        }
        else {
            return 1;
        }
    }
}

int maxsize = 0;
int step = 0;

TrieNode* deletes(string key, TrieNode* node, int size, int depth){
    step++;

    if(!node) return NULL;

    // if the leaf is the last char in a string
    if(depth == size){
        if (isLeaf(node)){
            delete(node);
            node = NULL;
            maxsize++;
        }
        return node;
    }

    if(node->children[key[depth] - 'a'] && step == size){
        node->children[key[depth] - 'a'] -> val = 0;
    }

    //checks for the following leaf, bc 
    int i = key[depth] - 'a';
    node->children[i] = deletes(key, node->children[i], size, depth++);
    
    return node;
}


void Trie::remove(string key){
    step = 0;
    this->root = deletes(key, this->root, key.length(), 0);
    tree_size -= maxsize;
    map_size = map_size - 1;
    
    maxsize = 0;
}
