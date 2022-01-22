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


void makeCycle(node* &head, int pos){
    int count =1;
    
    node* temp = head;
    
    node* startNode;
    
    while(temp->next != NULL){
        
        if(pos == count){
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startNode;
}

bool detectCycle(node* &head){
    
    node* slow = head;
    node* fast = head;
    
    while(fast != NULL & fast->next != NULL){
        
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return true;
        }
    }
    return false;
}

void remove_the_cycle(node* &head){
    node* slow  =  head;

    node* fast =  head;

    do{
        fast = fast->next->next;
        slow = slow->next;
    } while (fast != slow);

    fast = head;

    while(fast->next != slow->next){
        fast = fast->next;
        slow = slow ->next;
    }

    slow ->next = NULL;
    
}

void print_The_list(node* &head){
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

 //	starter();

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

 		//print_The_list(head);
 		
 		makeCycle(head, 3);
 		
 		// print_The_list(head);
 		
 	if(detectCycle(head)){
         cout<<"Cycle is present"<<endl;
     }
     else{
         cout<<"Cycle is not present"<<endl;
     }
 		

    remove_the_cycle(head);

    if(detectCycle(head)){
         cout<<"Cycle is present"<<endl;
     }
     else{
         cout<<"Cycle is not present"<<endl;
     }
 		
    
      

 	//1 2 3 4 5
 		



 }