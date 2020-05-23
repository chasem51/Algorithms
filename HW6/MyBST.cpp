// LATE DAY
// Chase Maivald
// U18719879

//  MyBST.cpp
//  bst_transform
//

#include "MyBST.h"
#include <queue>

/**
 * Computes how to transform this MyBST into the target MyBST using rotations.
 * Returns a vector of rotations indicating which rotations around which nodes
 * must be performed to transform this into the target.
 *
 * IMPORTANT: We want to transform T1 into T2 so the call should look like
 * rotations = t1.transform(t2)     */
// auto rotseq = start.transform(target);
Node* MyBST::in_order(int index){ // in order traversal
    queue<Node*> q;
    q.push(this->root);
    int count = 0;

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        count++;
        
        if (count == index) return temp;
        
        if (temp->left){
            q.push(temp->left);
        }
        
        if (temp->right){
            q.push(temp->right);
        }
    }
    
    return NULL; // after going through the tree
}

//searches for a node(found) with the same value as the node in root2 
Node* MyBST::search(int value){
    queue<Node*> q;
    q.push(this->root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if (temp->key == value) return temp;

        if (temp->left){
            //temp = temp->right; // segmentation fault
            q.push(temp->left);
        }

       if (temp->right){
            //temp = temp->left; //segmentation fault
            q.push(temp->right);
        }
    }

    return NULL;
}

int MyBST::getDepth(Node* node, Node* ptr, int height){
    if (node == NULL) return 0;

    if (node->key == ptr->key) return height;

    int depth = getDepth(node->left, ptr, height+1);

    if (depth != 0) return depth;

    return getDepth(node->right, ptr, height+1);
}


Node* MyBST::findParent(Node* root, int value){
    if ((root->left == NULL) && (root->right == NULL)) return NULL;

    if ((root->left != NULL && root->left->key == value) || (root->right != NULL && root->right->key == value)) return root;

    else if (root->key > value) return findParent(root->left, value);

    else if (root->key < value) return findParent(root->right, value);
}

vector<Rotation> MyBST::transform(MyBST target) {
    Node* root2 = target.root;
    int index = 1;
    vector<Rotation> rotations;
    
    while(root2){
        Node* found = this->search(root2->key);
        
        bool sameDepth = false;
        int depth2 = target.getDepth(target.root, root2, 1); // depth2 is depth of root2 in the second tree

        while(!sameDepth){
            int depth1 = this->getDepth(this->root, found, 1); //depth1 is depth of root2 in the first tree

            if (depth1 == depth2){
                sameDepth = true;
            }
            else{
                Node* foundparent = this->findParent(this->root, found->key); //foundparent is the parent Node of found
            
                if (found->key < foundparent->key){
                    Rotation rot(foundparent->key, ZIG);
                    rotations.push_back(rot);

                    if (foundparent->key == this->root->key){ // if the parent of found is the root node for the BST
                        this->root = rotateRight(foundparent);
                    }
                    
                    else{
                        Node* foundgrandparent = this->findParent(this->root, foundparent->key); //grandparent -- find the parent's parent
                        if (foundparent->key < foundgrandparent->key){ //if foundparent is left of foundgrandparent
                            foundgrandparent->left = this->rotateRight(foundparent);
                        }
                        else{
                            foundgrandparent->right = this->rotateRight(foundparent);
                        }
                    }
                }

                else if (found->key > foundparent->key){ // found is on the right of its parent
                    //ZAG on foundparent
                    Rotation rot(foundparent->key, ZAG);
                    rotations.push_back(rot);
                    if (foundparent->key == this->root->key){
                        this->root = rotateLeft(foundparent);
                    }
                    else{
                        Node* foundgrandparent = this->findParent(this->root, foundparent->key);
                        if (foundparent->key < foundgrandparent->key){ //if parent of found is on the left of grandparent of found
                            foundgrandparent->left = this->rotateLeft(foundparent);
                        }
                        else{
                            foundgrandparent->right = this->rotateLeft(foundparent);
                        }                    
                    }
                }
            }
        }
        index++;
        
        root2 = target.in_order(index);
    }
    return rotations;
}

Node* MyBST::rotateRight(Node* Q)
{
    Node* P = Q->left; // set P to Q's left child
    Q->left = P->right; // set Q's left subtree to P's right subtree
    P->right = Q; // put Q as P's right child
    return P;
}

Node* MyBST::rotateLeft(Node* P)
{
    Node* Q = P->right; // set Q to P's right child
    P->right = Q->left; // turn q's left subtree into P's right subtree
    Q->left = P; // put P as Q's left child
    return Q;
}