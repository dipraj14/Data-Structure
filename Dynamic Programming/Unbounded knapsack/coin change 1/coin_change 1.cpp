

// https://leetcode.com/problems/coin-change-2/submissions/

// no of ways to do sum 


#include <bits/stdc++.h>
using namespace std;

int coinChange_1(int coin[], int n, int sum)
{
	
	int dp[n + 1][sum + 1];


	for (int i = 0; i <= n; i++){
		dp[i][0] = 1;
	}

	
	for (int i = 1; i <= sum; i++){
		dp[0][i] = 0;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if ( coin[i - 1] <= j){

				dp[i][j] = dp[i - 1][j] + dp[i][j - coin[i - 1]] ;
			}
			else{

				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	

	return dp[n][sum];
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
    
    cout<< "possible way to make sum is : "<< coinChange_1(coin,n,sum);
    }

