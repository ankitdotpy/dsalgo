#include<bits/stdc++.h>
#include"linkedlist.h"
using namespace std;

// Iterative version
struct node* reverseListIter(struct node *head){
	struct node *temp = nullptr,*nextNode = nullptr;
	while(head){
		nextNode = head->next;
		head->next = temp;
		temp = head;
		head = nextNode;
	}

	return temp;
}

//Recursive Version
struct node* reverseListRec(struct node *head){
	if(!head or !(head->next))
		return head;

	struct node *temp = head->next;
	struct node *rev = reverseListRec(head->next);
	head->next = nullptr;
	temp->next = head;

	return rev;
}

int main(){
	LinkedList l = LinkedList();
	int t; cin>>t;
	while(t--){
		int a;
		cin>>a;
		l.insertNode(a);
	}

	struct node *r1 = reverseListRec(l.head);
	struct node *r2 = reverseListIter(l.head);
	LinkedList l1 = LinkedList(r1);
	l1.printList();
}