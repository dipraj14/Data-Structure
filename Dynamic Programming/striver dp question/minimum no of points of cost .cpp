// https://leetcode.com/problems/maximum-number-of-points-with-cost/

#include<bits/stdc++.h>
using namespace std;

int f(int row,int n, int m, int prevcol,vector<vector<int>> &matt, vector<vector<int>> dp ){   // tc -> (n*m) * m --> aprox o(n^3)
    if(row == n){
        return 0;
    }

    if(dp[n][m] != -1){
        return dp[n][m];
    }
    
       int maxi = INT_MIN;
    for(int col=0; col<m; col++){
        maxi = max(maxi, matt[row][col] - abs(col-prevcol) + f(row+1, n, m, col, matt, dp) );
    }

    return dp[row][prevcol] = maxi;
}
void solve(int n, int m, vector<vector<int>> &matt){
    int ans = INT_MIN;

    vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
    for(int col =0; col<m; col++){
        ans = max(ans, matt[0][col] + f(1, n, m, col, matt, dp) );
    }

   cout<<  ans;
   

}

int ittritive_dp(int n, int m , vector<vector<int>> &matt){
    vector<vector<int>> dp(n,vector<int> (m));
    
    for(int row = n-1; row>=0; row--){
        for(int col = 0; col <m ;col++){

            if(row == n-1){
                dp[row][col] = matt[row][col];
            }
            else{
                //int maxi  =INT_MIN;
                dp[row][col] = INT_MIN;

                for(int prevcol = 0; prevcol<m; prevcol++){
                    dp[row][col] = max(dp[row][col], matt[row][col] - abs(col - prevcol) + dp[row+1][prevcol]);
                }

            }

        }
    }
    return dp[0][0];
}
int ittritive_dp_space_optimize(int n, int m , vector<vector<int>> &matt){
    vector<int> dp(m,0);
    
    for(int row = n-1; row>=0; row--){

        vector<int> tempdp(m,0);

        for(int col = 0; col <m ;col++){

            if(row == n-1){
                tempdp[col] = matt[row][col];
            }
            else{
                //int maxi  =INT_MIN;
               

                for(int prevcol = 0; prevcol<m; prevcol++){
                    tempdp[col] = max(tempdp[col], matt[row][col] - abs(col - prevcol) + dp[prevcol]);
                }

            }

        }
        dp = tempdp;
    }

    return dp[m-1];
}

int main(){
    int n; // row
    int m; // col
    cin >> n >>m;

    vector<vector<int>> arr(n, vector<int> (m));

    for(int i=0; i<n;i++){
        for(int j=0; j<m; j++){

            cin >> arr[i][j];

        }
    }

    // solve(n, m, arr);
   // cout<< ittritive_dp( n,  m , arr);
    cout<< ittritive_dp_space_optimize( n,  m , arr);
}