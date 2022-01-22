
/*
#include<bits/stdc++.h>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }
int knapsack(int W,int wt[],int val[], int n){

	if(n == 0 || W==0){
		return 0;
	}
   
	int lef = INT_MIN;
	int right= INT_MIN;

	if(wt[n-1] <=W){
		lef = val[n-1]+ knapsack(W-wt[n-1], wt, val, n-1) ;
	}
	else{
		right = knapsack(W,wt,val,n-1);
	}
	return max(lef, right);
}
int main(){


	int n;
	cin >> n;

	int wt[n],val[n];

	for(int i = 0;i<n;i++){
		cin >>wt[i];
	}
	for(int i = 0;i<n;i++){
		cin >>val[i];
	}

	int W;
	cin >>W;


	cout<< knapsack(W, wt, val , n);

}
*/

#include<bits/stdc++.h>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }
int knapsack(int W,int wt[],int val[], int n){

	if(n == 0 || W==0){
		return 0;
	}


	if(wt[n-1] <=W){
		return max( val[n-1]+ knapsack(W-wt[n-1], wt, val, n-1) ,knapsack(W,wt,val,n-1) );
	}
	else{
		return knapsack(W,wt,val,n-1);
	}
	
}
int main(){


	int n;
	cin >> n;

	int wt[n],val[n];

	for(int i = 0;i<n;i++){
		cin >>wt[i];
	}
	for(int i = 0;i<n;i++){
		cin >>val[i];
	}

	int W;
	cin >>W;


	cout<< knapsack(W, wt, val , n);

}