// atcoder.jp/contests/dp/submissions/me


#include <bits/stdc++.h>

using namespace std;


int frogJUMP(int n, vector<int> &arr, int k){   // tebulation
       
    int dp[n] ;

    dp[n-1] = 0;

    for(int i=n-2; i>=0 ;i--){
        dp[i] = INT_MAX;

        for(int steps= 1; steps<=k; steps++){

            if(i+ steps < n){

                dp[i] = min (dp[i], (abs(arr[i] - arr[i+steps])+ dp[i+ steps]) );
            }
            else{
                break;
            }

        }
    }

    return dp[0];



}



int main()
{
    int n;
    int k;
    cin >> n >> k;
    vector<int> arr(n);
  
    for(int i=0; i<n ;i++){
        cin >> arr[i];
    }

 
    cout << frogJUMP(n, arr, k) ; // reculsive tebulation 


    
    
    
    

    return 0;
}
