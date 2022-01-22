
#include <bits/stdc++.h>
using namespace std;

int count_subset(int set[], int n, int sum)
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
			if ( set[i - 1] <= j){

				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - set[i - 1]] ;
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

    int set[n];
    for(int i=0;i<n;i++){
        cin >> set[i];
    }
    int sum;
    cin>> sum;
    
   int count = count_subset(set, n, sum);
    
    if(count > 0){
         cout <<"no of subsent which is equal to given sum: " << count  ;
    }
    else{
        cout <<"No subset with given sum: " << count;
    }
    return 0;
}

