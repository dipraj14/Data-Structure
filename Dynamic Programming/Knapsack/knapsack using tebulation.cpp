#include<bits/stdc++.h>
using namespace std;




int knapsack(int W,int wt[],int val[], int n){

	vector<vector<int> > dp(n+1,vector<int> (W+1));
  
  for(int i=0;i<n+1;i++){
  	for(int j=0;j<W+1;j++){
  		if(i == 0 || j == 0){
  			dp[i][j] =0;
  		}
  		else if(wt[i-1] <= j){
  			dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
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

	int W;
	cin >>W;

	int wt[n],val[n];

	for(int i = 0;i<n;i++){

		cin >> wt[i] >> val[i];
	}

	 

	
	// memset(dp, -1 , sizeof(dp));
    
	cout<< knapsack(W, wt, val , n);

}

/*
int knapsack(int W,int wt[],int val[], int n){

	vector<int> dp(W+1,0);
  
  for(int i=1;i<n+1;i++){
	  vector<int> tempdp(W+1,0);
  	for(int j=1;j<W+1;j++){
  	
  	   if(wt[i-1] <= j){
  			tempdp[j] = max(val[i-1]+dp[j-wt[i-1]], tempdp[j]);
  		}
  		else{
  		   tempdp[j] = tempdp[j];
  		}

		dp = tempdp;
  	}

  }
 

  return dp[W];
}

*/