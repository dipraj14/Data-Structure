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


  void deletAt_head(node* &head){
 	node* todelete = head;

 	head = head->next;

 	delete todelete;
 }


 void deletion(node* &head,int key){

 	node* temp = head;

	 

 	if(head->next == NULL || temp->data == key){
 		deletAt_head(head);
 		return;
 	}

 	while(temp->next->data != key){
 		temp = temp->next;
 	}

 	node* toDelete = temp->next;

 	temp->next = temp->next ->next;

 	delete toDelete;

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

 		int key;
 		cin >>key;

 		print_The_list(head);

 		deletion(head,key);



 		print_The_list(head);


 		deletAt_head(head);

 		print_The_list(head);
 		



 }