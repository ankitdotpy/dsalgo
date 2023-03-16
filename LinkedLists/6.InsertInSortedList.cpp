#include<bits/stdc++.h>
#include"linkedlist.h"
using namespace std;

void insertInSorted(struct node **head, int data){
	struct node *newNode = new node(data);
	if(!(*head)){
		*head = newNode;
		return;
	}

	struct node *temp = *head;
	while(temp->next and temp->data<data){
		temp = temp->next;
	}

	newNode->next = temp->next;
	temp->next = newNode;
}

int main(){
	LinkedList l = LinkedList();
	int t;
	cin>>t;
	while(t--){
		int a;
		cin>>a;
		l.insertNode(a);
	}

	int a; cin>>a;
	insertInSorted(&l.head,a);
	l.printList();
}