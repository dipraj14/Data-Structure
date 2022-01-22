
// 
// 
// https://codeforces.com/contest/1285/problem/B

#include<bits/stdc++.h>
using namespace std;

#define int long long int


int kadens_algo(int a[], int start, int end){

   int mx_so_far = LLONG_MIN, cur = 0;

    for(int i = start; i < end; i++){

        cur += a[i];

       // cur = max(cur, a[i]);

        mx_so_far = max(mx_so_far, cur);

        if(cur < 0){

            cur =0;

        }
    }
 

    return mx_so_far;
   
}

int final(int arr[], int n){

    int final_sum;
    final_sum = max(kadens_algo(arr,0,n-1), kadens_algo(arr,1,n));

    return final_sum;

}

signed main(){

 int t;
 cin >>t;
 while(t--){

    int n;
    cin >> n;

    int arr[n];
    int sum = 0;

    for(int i=0;i<n;i++){
        cin >>arr[i];
        sum+=arr[i];
    }
    
   

    if(sum > final( arr,n) ) {
        cout<< "YES" <<endl;
    }
    else{
        cout <<"NO"<<endl;
    }

 }



}