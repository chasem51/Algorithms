#ifndef __MYBST_H__
#define __MYBST_H__

#include <vector>
#include "BST.h"

struct Pair{
    Node* parent;
    Node* child;
};

class MyBST : public BST
{
    using BST::BST;
public:
    std::vector<Rotation> transform(MyBST target);
    bool isParent(Node* parent, Node* child);
    bool isLeftParent(Node* parent, Node* child);
    bool isRightParent(Node* parent, Node* child);
    bool isRoot(Node* rootNode);
    bool rotateRight(Node* root, Node* pivot, Node* parent);
    bool rotateLeft(Node* root, Node* pivot, Node* parent);
    Node* findParentLastRightSpineBranch();

    vector<Rotation> makeRightChain(RotationType rotType);
    void reverse(vector<Rotation> input);
};

#endif /* __MYBST_H__*/