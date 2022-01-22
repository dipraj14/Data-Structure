#include<bits/stdc++.h>

using namespace std;

bool subsetSum(int a[], int n , int g_sum){
   
    bool dp [ n+1][g_sum+1];

    for(int i=0 ;i<= n;i++){
        dp[i][0] = true;
    }
    for(int i=1; i<=n ;i++){
        dp[0][i] = false;
    }
    for(int i=1;i<= n;i++){
        for(int j=1; j<=g_sum ;j++){

            if(a[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j] || dp[i-1][j-1];
            }
        }
    }
}


int main(){


    int n;
    cin >> n;
    int a[n];

    for(int i=0 ;i <n ;i++){
        cin >>a[i];
    }

    int sum =0 ;

    for(int i=0;i<n;i++){
        sum += a[i];
    }

    if(sum %2 != 0){
        cout<< "Equal partation will not possible"<<endl;
    }
    else{
        if(subsetSum(a, n , sum/2) == true){
            cout<<" Equal partation will possible "<< endl;
        }
        else{
            cout<< "Equal partation will not possible"<< endl;
        }
    }
}