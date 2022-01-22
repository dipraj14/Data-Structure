#include <bits/stdc++.h>

using namespace std;

int lcs(int m,int n, string s1, string s2){
    
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

int  minimum_no_of_INSERT_DETATION(string s1, string s2, int lcs_str_len){

    int mini_delet_intert = lcs_str_len + (s2.length() - lcs_str_len);

    return mini_delet_intert;
}


int main()       // overall TC -> o(m*n)
{
   string s1 ;  // heap
   string s2 ;  // pea

   cin >> s1 >> s2;

  
   
    int lcs_str_length =  lcs(s1.size(),s2.size(),s1,s2);  // ea



    cout<<"MINIMUM no of INSERTION and DELETATION oprration make string 1 to string 2 : "<< minimum_no_of_INSERT_DETATION(s1, s2, lcs_str_length);

    return 0;
}