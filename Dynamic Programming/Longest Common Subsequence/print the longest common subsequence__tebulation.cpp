#include <bits/stdc++.h>

using namespace std;

string lcs(int m,int n, string s1, string s2){
    

    string ans;
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

    int i = m;
    int j = n;

    while(i>0 && j>0){
        if(s1[i-1] == s2[j-1]){
            ans.push_back(s1[i-1]);
            i--;
            j--;
        }
        else{
            if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }

    reverse(ans.begin(), ans.end());

    return ans;
    
}

int main()       // overall TC -> o(m*n)
{
   string s1 ;
   string s2 ;

   cin >> s1 >>s2;

  
   
    cout<< lcs(s1.size(),s2.size(),s1,s2);

    return 0;
}