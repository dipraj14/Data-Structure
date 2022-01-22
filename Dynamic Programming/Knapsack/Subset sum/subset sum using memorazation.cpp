#include <bits/stdc++.h>
using namespace std;
 

bool isSubsetSum(int set[], int n, int sum, vector<vector<bool>> &dp)
{
   
    // Base Cases
    if (sum == 0)
        return true;
    if (n <= 0)
        return false;
 
    if(dp[n][sum] != -1){
        return dp[n][sum];
    }
    if (set[n - 1] > sum){
        dp[n][sum] = isSubsetSum(set, n - 1, sum,dp);
    }
    else{
        dp[n][sum] =  isSubsetSum(set, n - 1, sum,dp) || isSubsetSum(set, n - 1, sum - set[n - 1],dp);
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

    starter();
    int n;
    cin >>n;

    int set[n];
    for(int i=0;i<n;i++){
        cin >> set[i];
    }
    int sum;
    cin>> sum;

    vector<vector<bool>> dp(n+1,vector<bool>(sum+1,-1));
    
    if (isSubsetSum(set, n, sum,dp) == true){
         cout <<"Found a subset with given sum";
    }
    else{
        cout <<"No subset with given sum";
    }
    return 0;
}