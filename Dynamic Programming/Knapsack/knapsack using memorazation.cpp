#include<bits/stdc++.h>
using namespace std;

#define int long long int
int knapsack(int W,int wt[],int val[], int n,vector<vector<int> > &dp){

	if(n == 0 || W==0){
		return n== 0 ? 0: INT_MIN;
	}
	if(dp[n][W] != -1){
		return dp[n][W];
	}

	if(wt[n-1] <=W){
		 return dp[n][W] = max(val[n-1]+knapsack(W-wt[n-1], wt, val, n-1,dp), knapsack(W,wt,val,n-1,dp));
	}
	else{
		return dp[n][W] = knapsack(W,wt,val,n-1,dp);
	}
}

signed main(){

	int n;
	int W;

	cin >> n >> W;



	int wt[n],val[n];

	for(int i = 0;i<n;i++){
		cin >>wt[i] >> val[i];
	}
	//for(int i = 0;i<n;i++){
		//cin >>val[i];
	//}

	//int W;
	//cin >>W;
	vector<vector<int> > dp(n+1,vector<int> (W+1, -1));
	// memset(dp, -1 , sizeof(dp));
    
	cout<< knapsack(W, wt, val , n,dp);

}