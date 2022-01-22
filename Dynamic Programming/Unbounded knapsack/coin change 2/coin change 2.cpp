

// Return the fewest number of coins that you need to make up that amount.
//https://leetcode.com/problems/coin-change/submissions/

#include <bits/stdc++.h>
using namespace std;

int coinChange_2(int coin[], int n, int sum)
{
	
	int dp[n + 1][sum + 1];


	for (int i = 1; i <= n; i++){
		dp[i][0] = 0;
	}

	
	for (int i = 0; i <= sum; i++){
		dp[0][i] = INT_MAX-1;
	}

    for(int j=1;j<=sum;j++){
        if(j% coin[0] == 0){
            dp[1][j] = j/coin[0];
        }
        else{
            dp[1][j] = INT_MAX-1;
        }
    }

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if ( coin[i - 1] <= j){

				dp[i][j] = min( dp[i - 1][j] , 1+ dp[i][j - coin[i - 1]] );
			}
			else{

				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	

	if(dp[n][sum] == INT_MAX-1){
        return -1;
    }
    else{
        return dp[n][sum];
    }
}


void starter(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}



int main()
{
	//starter();

    int n;
    cin >>n;

    int coin[n];
    for(int i=0;i<n;i++){
        cin >> coin[i];
    }

    int sum;
    cin>> sum;

      
 
    
        cout<< "minimum elemevt requried to make sum is : "<< coinChange_2(coin,n,sum);
    
  
    
    }

