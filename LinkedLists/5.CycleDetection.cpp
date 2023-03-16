#include<bits/stdc++.h>
#include"linkedlist.h"
using namespace std;

bool containsCycle(struct node *head){
	struct node *slow,*fast;
	slow = fast = head;

	while(slow and fast and fast->next){
		slow = slow->next;
		fast = fast->next->next;

		if(slow==fast){
			return true;
		}
	}

	return false;
}

struct node* getLoopStartNode(struct node *head){
	struct node *slow,*fast;
	slow = fast = head;
	bool loop = false;
	while(slow and fast and fast->next){
		slow = slow->next;
		fast = fast->next->next;

		if(slow==fast){
			loop = true;
			break;
		}
	}

	if(loop){
		slow = head;
		while(slow!=fast){
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
	}

	return nullptr;
}

int loopLength(struct node *head){
	struct node *slow,*fast;
	slow = fast = head;

	bool flag = false;
	while(slow and fast and fast->next){
		slow=slow->next;
		fast = fast->next->next;
		if(slow==fast){
			flag = true;
			break;
		}
	}
		
	int len = 0;
	if(flag){
		fast = fast->next;
		while(fast!=slow){
			len++;
			fast = fast->next;
		}
		return len;
	}

	return 0;
}

int main(){
	LinkedList l1 = LinkedList();
	LinkedList l2 = LinkedList();

	int t; cin>>t;
	while(t--){
		int data;
		cin>>data;
		l1.insertNode(data);
		l2.insertNode(data);
	}

	struct node *temp = l2.head;
	while(temp->next){
		temp = temp->next;
	}

	temp->next = l2.head;

	cout<<containsCycle(l1.head)<<endl;
	cout<<containsCycle(l2.head)<<endl;
	auto ptr = getLoopStartNode(l2.head);
	cout<<ptr->data<<endl;

	int len = loopLength(l2.head);
	cout<<len<<endl;
}