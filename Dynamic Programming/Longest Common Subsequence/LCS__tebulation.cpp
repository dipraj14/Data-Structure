/*
#include <bits/stdc++.h>

using namespace std;

int lcs(int m,int n, string s1, string s2){
    
    // base case

    int dp[m+1][n+1];

    for(int i=0; i<=n; i++){
        dp[0][i] = 0;
    }

    for(int i=1; i<=m; i++){
        dp[i][0] = 0;
    }
    
    for(int i=1; i<=m ; i++){
        for(int j=1; j<=n ;j++){

            if(s1[i-1] == s2[j-1]){
                dp[i][j] =  1+ dp[i-1][j-1];
            }
            else{

                 int left =  dp[i-1][j]; // left
                 int right = dp[i][j-1];  // right
        
                 dp[i][j] = max(left,right);

            }

        }
    }

    return dp[m][n];
    
}

int main()       // overall TC -> o(m*n)
{
   string s1 ;
   string s2 ;

   cin >> s1 >>s2;

  
   
   cout<< "LCS is: "<< lcs(s1.size(),s2.size(),s1,s2);

    return 0;
}


*/



// space optimazation 

#include <bits/stdc++.h>

using namespace std;

int lcs_0_to_n (int m,int n, string s1, string s2){
    
    // base case

    vector<int> dp(m+1,0);

  
    
    for(int i=1; i<=m ; i++){
        vector<int> tempdp(m+1,0);
        for(int j=1; j<=n ;j++){

            if(s1[i-1] == s2[j-1]){
                tempdp[j] =  1+ dp[j-1];
            }
            else{

        
                 tempdp[j] = max(dp[j], tempdp[j-1]);

            }

        }
        dp = tempdp;
    }

    return dp[m-1];
    
}
int lcs_n_to_0_ (int m,int n, string s1, string s2){
    
    // base case

    vector<int> dp(m+1,0);

  
    
    for(int i=n-1; i>=0 ; i--){
        vector<int> tempdp(m+1,0);
        for(int j=m-1; j>=0 ;j--){

            if(s1[i] == s2[j]){
                tempdp[j] =  1+ dp[j+1];
            }
            else{

        
                 tempdp[j] = max(dp[j], tempdp[j+1]);

            }

        }
        dp = tempdp;
    }

    return dp[0];
    
}


int main()       // overall TC -> o(m*n)
{
   string s1 ;
   string s2 ;

   cin >> s1 >>s2;

  
   
   cout<< "LCS is: "<< lcs_0_to_n(s1.size(),s2.size(),s1,s2);

    return 0;
}