#include<bits/stdc++.h>
#include"linkedlist.h"
using namespace std;


// One approach could be to iterate to the end of list and 
// find its length. Then nth node from end is (Len - n + 1)th
// node from front

// Another approach is to take two pointers p1 and p2
// Start moving p2 first and then start moving p1 after
// p2 has made n moves. When p2 reaches the end of list
// then p1 will be at nth node from end.

struct node* nthNodeFromEnd(struct node *head, int n){
	struct node *p1,*p2;
	p1 = p2 = head;

	for(int i=0;i<n;i++){
		p2 = p2->next;
	}

	while(p2){
		if(p1)
			p1 = p1->next;
		p2 = p2->next;
	}

	if(p1)
		return p1;

	return nullptr;
}

int main(){
	LinkedList l = LinkedList();
	int t;
	cin>>t;
	while(t--){
		int data;
		cin>>data;
		l.insertNode(data);
	}

	int n;
	cin>>n;
	auto ans = nthNodeFromEnd(l.head,n);
	if(ans)
		cout<<ans->data<<'\n';

	return 0;
}