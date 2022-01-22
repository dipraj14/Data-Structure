#include <bits/stdc++.h>

using namespace std;

int longest_Common_Substring(int m,int n, string s1, string s2){
    
    // base case

    int dp[m+1][n+1];

    int res = INT_MIN;

    for(int i=0; i<=n; i++){
        dp[0][i] = 0;
    }

    for(int i=1; i<=m; i++){
        dp[i][0] = 0;
    }
    int endIdx;
    for(int i=1; i<=m ; i++){
        for(int j=1; j<=n ;j++){

            if(s1[i-1] == s2[j-1]){
                dp[i][j] =  1+ dp[i-1][j-1];
                //res = max(res, dp[i][j]);

                if( res < dp[i][j]){
                    res = dp[i][j];

                    endIdx = i;
                }
            }
            else{
        
                 dp[i][j] = 0; 
            }

        }
    }

    cout <<" LONGEST COMMON SUBSTRING IS: "  << s1.substr(endIdx - res, res) << endl;

    return res;
    
}

int main()       // overall TC -> o(m*n)
{
   string s1 ;
   string s2 ;

   cin >> s1 >>s2;

  
   
   cout<< "longest Common Substring length is: "<< longest_Common_Substring(s1.size(),s2.size(),s1,s2);

    return 0;
}