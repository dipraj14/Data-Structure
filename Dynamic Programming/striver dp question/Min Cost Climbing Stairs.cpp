
#include <bits/stdc++.h>

using namespace std;



int miniCost(int idx, int n,  vector<int> &arr){   // reculsion

    if(idx == n){
        return 0;
    }
    int cost1 = arr[idx] + miniCost(idx+1, n , arr);

   int cost2= INT_MAX;

    if(idx+2 <= n){
        cost2 = arr[idx] + miniCost(idx+2, n , arr) ;

    }

    return min(cost1,cost2);
}

int miniCost__tedulation ( int n,  vector<int> &arr){ // dp -- > tebulation 


    vector<int> dp(n+1);
    dp[n] = 0;

    for(int i=n-1; i>=0; i--){

        dp[i] = arr[i] + dp[i+1];

        if(i+2 <= n){
            dp[i] = min(dp[i] , arr[i]+dp[i+2] );
        }
    }

    

    return min(dp[0], dp[1]);
}

int miniCost__memorazation ( int idx, int n,  vector<int> &arr, vector<int> &dp){ // dp -- > tebulation 


    if(idx == n){
        return 0;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    int cost1 = arr[idx] + miniCost(idx+1,n , arr);
    int cost2 = INT_MAX;

    if(idx+2 <= n){
        cost2 = min(cost1, (arr[idx] + miniCost(idx+2,n , arr) ) ) ;

    }

    return dp[idx] = min (cost1, cost2);
}




int main()
{
    int n;
    int k;
    cin >> n ;
    vector<int> arr(n);
  
    for(int i=0; i<n ;i++){
        cin >> arr[i];
    }

    vector<int> dp(n+1, -1);

 
    cout << min( miniCost(0, n, arr) , miniCost(1, n, arr) );            // reculsion

   // cout<<  miniCost__tedulation(n, arr);

    //cout << min( miniCost__memorazation(0, n, arr, dp) , miniCost__memorazation(1, n, arr , dp) );


    
    
    
    

    return 0;
}
