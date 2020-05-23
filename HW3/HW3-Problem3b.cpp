#include <iostream>

#include "ListNode.h"

using namespace std;

ListNode* insertionSortList(ListNode* head) {

	ListNode *start = head;

	ListNode *insert = start; // insertion ptr to insert data

	head = head->next;

	while(head != NULL){ // avoid seg fault
		insert = start;
		//head = head->next;
		while(insert != head){
			if(insert->val < head->val){
				int temp = head->val; // store head's data so it is not lost
				head->val = insert->val; // move the smaller int into location of head
				insert->val = temp;	// move the larger int into location of insert
			}
			else{
				insert = insert->next;
			}
		}
		head = head->next;
	}
	
	return start;
}
/*
void printList (struct ListNode* head){
	ListNode *temp = head;
	while(temp!=NULL){
		cout << temp->val << " ";
		temp = temp->next;
	}
}

void insertBegin(struct ListNode **head, int value){
	
	if(*head == NULL){
		struct ListNode *new_node = new ListNode(value);
		new_node = *head;
		new_node->val = value;
		new_node->next = *head;
		return;
	}
	
		struct ListNode *new_node = new ListNode(value);
		new_node->val = value;
		new_node->next = *head;
		*head = new_node;
}


int main()
{
	ListNode *start = new ListNode(NULL);
	//start->val = NULL;
	
	insertBegin(&start,1);

	insertBegin(&start,2);
	
	insertBegin(&start,4);

	insertBegin(&start,200);
	
	insertBegin(&start,20);

	cout << "Given Linked List: " << endl;
	printList(start);
	cout << endl;

	insertionSortList(start);

	cout << "Insertion Sorted List: " << endl;
	printList(start);
	cout << endl;

	delete start;

    return 0;
}
*/