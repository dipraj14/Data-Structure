#include<bits/stdc++.h>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }
int knapsack(int W,int wt[],int val[], int n,vector<vector<int> > &dp){

	if(n == 0 || W==0){
		return 0;
	}
	if(dp[n][W] != -1){
		return dp[n][W];
	}

	if(wt[n-1] <=W){
		 dp[n][W] = max(val[n-1]+knapsack(W-wt[n-1], wt, val, n,dp), knapsack(W,wt,val,n-1,dp));
	}
	else{
		dp[n][W] = knapsack(W,wt,val,n-1,dp);
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
	vector<vector<int> > dp(n+1,vector<int> (W+1, -1));
	// memset(dp, -1 , sizeof(dp));
    
	cout<< knapsack(W, wt, val , n,dp);

}