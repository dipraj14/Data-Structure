#include<bits/stdc++.h>

using namespace std;

bool subsetSum(int a[], int n , int g_sum, vector<vector<bool> > &dp){

    if(g_sum == 0){
        return true;
    }
    if(n == 0){
        return false;
    }

    if(dp[n][g_sum] != -1){
        return dp[n][g_sum];
    }

    if(a[n-1] > g_sum){
       dp[n][g_sum] =  subsetSum(a, n-1, g_sum, dp);
    }
    else{
        dp[n][g_sum] = subsetSum(a, n-1 ,g_sum, dp) || subsetSum(a,n-1, g_sum-a[n-1] , dp);
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

    vector<vector<bool> > dp( n+1, vector<bool> ( ( (sum/2)+1) , -1) );

    if(sum %2 != 0){
        cout<< "Equal partation will not possible"<<endl;
    }
    else{
        if(subsetSum(a, n , sum/2, dp ) == true){
            cout<<" Equal partation will possible "<< endl;
        }
        else{
            cout<< "Equal partation will not possible"<< endl;
        }
    }
}