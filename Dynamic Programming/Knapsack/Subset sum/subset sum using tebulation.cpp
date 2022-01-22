
#include <bits/stdc++.h>
using namespace std;

bool isSubsetSum(int set[], int n, int sum)
{
	
	bool dp[n + 1][sum + 1];


	for (int i = 0; i <= n; i++){
		dp[i][0] = true;
	}

	
	for (int i = 1; i <= sum; i++){
		dp[0][i] = false;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if ( set[i - 1] <= j){

				dp[i][j] = (dp[i - 1][j] || dp[i - 1][j - set[i - 1]] );
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
	starter();

    int n;
    cin >>n;

    int set[n];
    for(int i=0;i<n;i++){
        cin >> set[i];
    }
    int sum;
    cin>> sum;
    
    if (isSubsetSum(set, n, sum) == true){
         cout <<"Found a subset with given sum";
    }
    else{
        cout <<"No subset with given sum";
    }
    return 0;
}

