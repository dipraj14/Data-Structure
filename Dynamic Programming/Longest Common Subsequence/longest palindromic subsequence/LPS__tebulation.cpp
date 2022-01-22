#include <bits/stdc++.h>

using namespace std;

int LPS(int m,int n, string s1, string s2){   // lps is same as LCS 
    

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
   

   cin >> s1 ;

   string s2(s1.rbegin(),s1.rend());

  
   
    cout<< LPS (s1.size(),s2.size(),s1,s2);

    return 0;
}