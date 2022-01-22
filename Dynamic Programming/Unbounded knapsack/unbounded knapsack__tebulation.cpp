#include<bits/stdc++.h>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }
int knapsack(int W,int wt[],int val[], int n){

	vector<vector<int> > dp(n+1,vector<int> (W+1));
  
  for(int i=0;i<n+1;i++){
  	for(int j=0;j<W+1;j++){
  		if(i == 0 || j == 0){
  			dp[i][j] =0;
  		}
  		else if(wt[i-1] <= j){
  			dp[i][j] = max(val[i-1]+ dp[i][j-wt[i-1]], dp[i-1][j]);
  		}
  		else{
  			dp[i][j] = dp[i-1][j];
  		}
  	}
  }
 

  return dp[n][W];
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
	// memset(dp, -1 , sizeof(dp));
    
	cout<< knapsack(W, wt, val , n);

}