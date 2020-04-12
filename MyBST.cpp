//
//  MyBST.cpp
//  bst_transform
//

#include "MYBST.h"

/**
 * Computes how to transform this MyBST into the target MyBST using rotations.
 * Returns a vector of rotations indicating which rotations around which nodes
 * must be performed to transform this into the target.
 *
 * IMPORTANT: We want to transform T1 into T2 so the call should look like
 * rotations = t1.transform(t2)     */
// auto rotseq = start.transform(target);

vector<Rotation> MyBST::transform(MyBST target) {

    /*** Your implementation should go here. ***/
    // target is passed into the rotation func
    //std::vector<Rotation> rotations(15);
    vector<Rotation> rotationVectorMe;
    vector<Rotation> rotationVectorTarget;

    rotationVectorMe = this->makeRightChain(ZIG);

    rotationVectorTarget = target.makeRightChain(ZAG);

    reverse(rotationVectorTarget);

    rotationVectorMe.insert(rotationVectorMe.end(),rotationVectorTarget.begin(),rotationVectorTarget.end());

    return rotationVectorMe;
}

bool MyBST::isLeftParent(Node* parent, Node* child){
    bool leftParent = false;

    if(parent && parent->right){
        if(parent->right == child){
            leftParent = true;
        }
    }
    return leftParent;
}

bool MyBST::isRightParent(Node* parent, Node* child){
    bool rightParent = false;

    if(parent && parent->right){
        if(parent->right == child){
            rightParent = true;
        }
    }
    return rightParent;
}

bool MyBST::isParent(Node* parent, Node* child){
    return(isLeftParent(parent,child) || isRightParent(parent,child));
}

bool MyBST::isRoot(Node* rootNode){
    if(this->root == rootNode){
        return true;
    }
    else{
        return false;
    }
}

bool MyBST::rotateRight(Node* root, Node* pivot, Node* parent){
    if(!parent && !isRoot(root)){
        return false;
    }
    
    if(parent && !(isParent(parent,root))){ // sf
        return false;
    }
    
    if(!(root && pivot)){
        return false;
    }
    if(!isLeftParent(root,pivot)){
        return false;
    }
    root->left = pivot->right;
    pivot->right = root;

    if(parent){
        if(isLeftParent(parent,root)){
            parent->left = pivot;
        }
        else{
            parent->right = pivot;
        }
    }
    else{
        this->root = pivot;
    }
    return true;
}

bool MyBST::rotateLeft(Node* root, Node* pivot, Node* parent){
    if(!parent && !isRoot(root)){
        return false;
    }
    if(parent && !(isParent(parent,root))){
        return false;
    }
    if(!(root && pivot)){
        return false;
    }
    if(!isRightParent(root,pivot)){
        return false;
    }
    root->right = pivot->left;
    pivot->left = root;

    if(parent){
        if(isLeftParent(parent,root)){
            parent->left = pivot;
        }
        else{
            parent->right = pivot;
        }
    }
    else{
        this->root = pivot;
    }
    return true;
}

Node* MyBST::findParentLastRightSpineBranch(){
    Node* branchParent = nullptr;
    Node* current = this->root;

    while(current){
        if(current->right && current->right->left){ // sf
            branchParent = current;
        }
        current = current->right;
    }
    return branchParent;
}

vector<Rotation> MyBST::makeRightChain(RotationType rotType){
    Node* nextBranch = nullptr;
    vector<Rotation> rotations;
    int rotationKey;

    while(true){
        nextBranch = findParentLastRightSpineBranch(); // sf
        if(nextBranch){
            rotationKey = nextBranch->right->left->key;
            rotateRight(nextBranch->right, nextBranch->right->left,nextBranch); // sf
            rotations.push_back(Rotation(rotationKey,rotType)); // sf
        }
        else{
            if(this->root && this->root->left){
                rotationKey = this->root->left->key;
                rotateRight(this->root,this->root->left,nullptr);
                rotations.push_back(Rotation(rotationKey,rotType));
            }
            else{
                break;
            }
        }
    }
    return rotations;
}

void MyBST::reverse(vector<Rotation> input){
    if(input.size() == 0){
        return;
    }
    Rotation temp = input.at(0);

    for(int forward = 0,back = input.size()-1;forward<input.size()/2;forward++,back--){
        temp = input.at(forward);
        input.at(forward) = input.at(back);
        input.at(back) = temp;
    }
}