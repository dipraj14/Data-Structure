#include<bits/stdc++.h>

using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }
int rod_cutting(int N,int len[],int price[], int n){

    	vector<vector<int> > dp(n+1,vector<int> (N+1));

    for(int i=0;i<n+1;i++){
  	    for(int j=0;j<N+1;j++){
           	if(i == 0 || j == 0){
  			    dp[i][j] =0;
  		    }
  		    else if(len[i-1] <= j){
  			    dp[i][j] = max(price[i-1]+ dp[i][j-len[i-1]], dp[i-1][j]);
  		    }
  		    else{
  			    dp[i][j] = dp[i-1][j];
  		    }
        }
    }

    return dp[n][N];


    
}
int main(){


	int n;
	cin >> n;

	int len[n],price[n];

     for(int i = 0;i<n;i++){
		cin >>len[i];
	}

      for(int i = 0;i<n;i++){
		cin >>price[i];
	}


	
	

	int N;
	cin >>N;


		cout<< rod_cutting(N, len, price , n);

}