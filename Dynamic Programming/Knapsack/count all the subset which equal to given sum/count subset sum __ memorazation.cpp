#include <bits/stdc++.h>
using namespace std;
 

int count_subset(int set[], int n, int sum, vector<vector<int>> &dp)
{
   
    // Base Cases
    if (sum == 0)
        return 1;
    if (n <= 0)
        return 0;
 
    if(dp[n][sum] != -1){
        return dp[n][sum];
    }
    if (set[n - 1] > sum){
        dp[n][sum] = count_subset(set, n - 1, sum,dp);
    }
    else{
        dp[n][sum] =  count_subset(set, n - 1, sum,dp) + count_subset(set, n - 1, sum - set[n - 1],dp);
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

    int set[n];
    for(int i=0;i<n;i++){
        cin >> set[i];
    }
    int sum;
    cin>> sum;

    vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
    
   int count = count_subset(set, n, sum, dp);
    
    if(count > 0){
         cout <<"no of subsent which is equal to given sum: " << count  ;
    }
    else{
        cout <<"No subset with given sum: " << count;
    }
    return 0;
}