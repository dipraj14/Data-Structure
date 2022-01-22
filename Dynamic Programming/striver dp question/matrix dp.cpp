

#include<bits/stdc++.h>
using namespace std;


int maxSum(int i, int j, vector<vector<int>> &a , int n, int m){  // using reculsion

    if(i<0 || j< 0|| j>=m || i>= n){
        return INT_MIN;
    }

    if(i == n-1 && j==m-1){
        return a[n-1][m-1];
    }

    int sum = a[i][j];

    sum+= max(maxSum(i+1,j,a,n,m), maxSum(i,j+1,a,n,m));

    return sum;

}
int maxSum_dp_memo (int i, int j, vector<vector<int>> &a ,vector<vector<int>> &dp , int n, int m){  // using reculsion

    if(i<0 || j< 0|| j>=m || i>= n){
        return INT_MIN;
    }

    if(i == n-1 && j==m-1){
        return a[n-1][m-1];
    }
    if(dp[n][m] != -1){
        return dp[n][m];
    }

    int sum = a[i][j];

    sum+= max(maxSum_dp_memo(i+1,j,a,dp, n,m), maxSum_dp_memo(i,j+1,a,dp,n,m));

    return dp[i][j] = sum;

}

void getpath(int i, int j,vector<vector<int>> &dp, vector<vector<int>> &a ,int n, int m){

    while( i != n-1 && j!= m-1){
        
        int maxi = dp[i][j] - a[i][j];
        if(i+1 < n && maxi == dp[i+1][j]){
            i = i+1;
        }
        if(j+1 < n){

            j = j+1;

        }
            
    
        cout<< i <<" " <<j <<endl;

    }

    
}
int maxSum_Dp ( vector<vector<int>> &a , int n, int m){  // using reculsion


    vector<vector<int>> dp(n+1, vector<int> (m+1));



    for(int i=n-1; i>=0; i--){
        for(int j=m-1; j>=0; j--){
            dp[i][j] = a[i][j];

            int maxi = 0;
            if(i+1 < n){
                maxi = dp[i+1][j];
            }
            if(j+1 < m) {
                maxi = max(maxi,dp[i][j+1]);
            }

            dp[i][j] += maxi;
        }
    }

    getpath(0,0, dp, a, n, m);;

    return dp[0][0];

   

}


int main(){

	int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m));
    for(int i=0; i<n; i++){
        for(int j=0; j< m; j++){

            cin >> a[i][j];

        }
    }

    vector<vector<int>> dp(n+1, vector<int> (m+1,-1));
    
	//cout<< maxSum(0,0, a, n ,m);
    //cout<< maxSum_Dp(a, n ,m);
    cout<< maxSum_dp_memo(0,0, a,dp, n ,m);

}
