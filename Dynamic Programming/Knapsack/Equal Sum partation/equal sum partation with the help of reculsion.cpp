#include<bits/stdc++.h>

using namespace std;

bool subsetSum(int a[], int n , int g_sum){

    if(g_sum == 0){
        return true;
    }
    if(n == 0){
        return false;
    }

    if(a[n-1] > g_sum){
        return subsetSum(a, n-1, g_sum);
    }
    else{
        return subsetSum(a, n-1 ,g_sum) || subsetSum(a,n-1, g_sum-a[n-1]);
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