#include<bits/stdc++.h>
#include"linkedlist.h"
using namespace std;

// Recursicve Version
struct node* mergeListRec(struct node *a, struct node *b){
	if(!a) return b;
	if(!b) return a;

	struct node *res = nullptr;
	if(a->data<b->data){
		res = a;
		res->next = mergeListRec(a->next,b);
	}
	else{
		res = b;
		res->next = mergeListRec(a,b->next);
	}

	return res;
}

struct node* mergeListIter(struct node *a, struct node *b){
	struct node *rec = nullptr;
	
}

int main(){

}