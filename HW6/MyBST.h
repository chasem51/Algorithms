// LATE DAY
// Chase Maivald
// U18719879

#ifndef __MYBST_H__
#define __MYBST_H__

#include <vector>
#include "BST.h"

class MyBST : public BST
{
    using BST::BST;
public:
    Node* in_order(int index);
    Node* search(int value);
	int getDepth(Node* node, Node* ptr, int height);
	Node* findParent(Node* root, int value);

	vector<Rotation>transform(MyBST target);
private:
	Node* rotateRight(Node* Q);
	Node* rotateLeft(Node* P);
};

#endif /* __MYBST_H__*/