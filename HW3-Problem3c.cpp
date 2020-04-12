#include <iostream>	

#include "ListNode.h"

using namespace std;

ListNode* findCycleStart(ListNode* head) {
	if (head == NULL || head->next == NULL) // return NULL if the list is empty/has one element
        return NULL; 
  
    ListNode *slow = head;
	ListNode *fast = head; 
   
    slow = slow->next; 
    fast = fast->next->next; // initialize two pointers for data stepping
  
    while (fast && fast->next) { 
        if (slow == fast) 
            break; 
        slow = slow->next; 
        fast = fast->next->next; // test for pointer overlap, ie, a cycle
    } 
  
    if (slow != fast){
		return NULL;
	} 
  
    slow = head; 
    while (slow != fast) { 
        slow = slow->next; 
        fast = fast->next; // if loop exists, point to its location with slow
    } 
  
    return slow; 
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

	insertBegin(&start,2);
	
	cout << "Given Linked List: " << endl;
	printList(start);
	cout << endl;

	start->next->next->next->next = start;

	cout << "Node where the cycle exists (0 if no cycle is present): " << endl;
	cout << findCycleStart(start) << endl;
	cout << endl;

	delete start;

    return 0;
}
*/
