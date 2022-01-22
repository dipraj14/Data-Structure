#include <bits/stdc++.h>

using namespace std;

int lcs(int m,int n, string s1, string s2, vector<vector<int>> &dp){
    
    // base case
    if(m==0 || n==0){
        dp[m][n]= 0;
    }
    if(dp[m][n] != -1){
        return dp[m][n];
    }
    
    if(s1[m-1] == s2[n-1]){
        dp[m][n] =  1+lcs(m-1,n-1,s1,s2, dp);
        return dp[m][n];
    }
    else{
        int left = lcs(m-1, n, s1, s2, dp); // left
        int right = lcs(m, n-1, s1, s2 , dp);  // right
        
        dp[m][n] = max(left,right);
    }
    
    
    
}

int main()       // overall TC -> o(m*n)
{
   string s1 ;
   string s2 ;

   cin >> s1 >>s2;

   vector<vector<int>> v(s1.size()+1, vector<int> (s2.size()+1, -1));
   
   cout<< "LCS is: "<< lcs(s1.size(),s2.size(),s1,s2, v);

    return 0;
}