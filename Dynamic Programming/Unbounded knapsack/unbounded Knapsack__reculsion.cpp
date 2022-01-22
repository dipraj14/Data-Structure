#include<bits/stdc++.h>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }
int knapsack(int W,int wt[],int val[], int n){

	if(n == 0 || W==0){
		return 0;
	}

	if(wt[n-1] <=W){
		return max(val[n-1]+knapsack(W-wt[n-1], wt, val, n), knapsack(W,wt,val,n-1));
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
		cin >>val[i];
	}

	for(int i = 0;i<n;i++){
		cin >>wt[i];
	}
	

	int W;
	cin >>W;


	cout<< knapsack(W, wt, val , n);

}