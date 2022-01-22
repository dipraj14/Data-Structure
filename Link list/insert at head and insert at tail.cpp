#include <bits/stdc++.h>

using namespace std;
 

 class node{
 public:
 	int data;
 	node* next;

 	node(int val){
 		data =val;
 		next =NULL;
 	}
 };

 void insertAt_Head(node* &head, int val){

 	node* n = new node(val);

 	n->next =head;

 	head = n;
 }

void insertAt_tail(node* &head, int val){

	node* n = new node(val);
	if(head == NULL){
		head = n;
		return;
	}
	node* temp =head;

	while(temp->next !=NULL){
		temp = temp->next;
	}
	temp->next = n;
}


void print_The_list(node* head){
	node* temp =head;
	while(temp!=NULL){

		cout<< temp->data <<"-> ";
		temp = temp->next;

	}
	cout<<"NULL"<<endl;
}

void starter(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

 int main(){

 	starter();

 		int n;
 		cin>> n;
 		int arr[n];

 		for(int i=0;i<n;i++){
 			cin >> arr[i];
 		}

 		node* head = NULL;
 		for(int i=0;i<n;i++){

 			insertAt_tail(head,arr[i]);

 		}

 		print_The_list(head);

 		insertAt_Head(head,10);

 		print_The_list(head);
 		



 }