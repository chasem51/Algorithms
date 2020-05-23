#ifndef LISTNODE_H
#include <cstddef>
#define LISTNODE_H

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
#endif