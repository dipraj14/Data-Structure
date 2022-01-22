// https://atcoder.jp/contests/dp/tasks/dp_a


#include <bits/stdc++.h>

using namespace std;



void get_path(int dp[], vector<int> &arr, int n){
    int idx =0;

   
    while(idx != n-1){

        cout<< idx << " "; // if 1 based indexing then idx+1

        if(dp[idx] - abs(arr[idx]-arr[idx+1]) == dp[idx+1]){
            idx += 1;
        }
        else{

            idx += 2;
        }

    }
    cout << idx <<" ";   // if 1 based indexing then idx+1
}


int frog_reculsion(int idx, int n, vector<int> arr){
    
     int secondJump;
    
    if(idx == n-1){
        return 0;
    }
    
    int firstJump = abs(arr[idx] - arr[idx+1]) + frog_reculsion(idx+1, n , arr);
    
    if(idx+2 <= n-1){
        
         secondJump =  abs(arr[idx] - arr[idx+2]) + frog_reculsion(idx+2, n , arr);
        
    }
    
   
    
    return min(firstJump, secondJump);
    
}
 
int frog_Jump(int idx, int n, vector<int> &arr, vector<int> &dp){   // memorazation
    
    int secondJump = INT_MAX;
    
    if(idx == n-1){
        return 0;
    }
    
    if(dp[n] != -1){
          return dp[n];
    }

    int firstJump = abs(arr[idx] - arr[idx+1]) + frog_reculsion(idx+1, n , arr);
    
    if(idx+2 <= n-1){
        
        secondJump =  abs(arr[idx] - arr[idx+2]) + frog_reculsion(idx+2, n , arr);
        
    }

  
       
    return dp[idx] =  min(firstJump, secondJump);

  

    

}




int frogJUMP(int n, vector<int> arr){   // tebulation
    
    int firstJump, secondJump= INT_MAX;
    
    int dp[n];
    
   dp[n-1] = 0;
   
   for(int i=n-2;i>=0;i--){
       firstJump = abs(arr[i] - arr[i+1]) + dp[i+1];
       
       if(i+2 < n){
           secondJump = abs(arr[i] - arr[i+2]) + dp[i+2];
       }
       
       dp[i] = min(firstJump, secondJump);
   }

 
   
    /* for(int i=0;i<n;i++){
        cout<<dp[i]<<" ";
    }
    cout<< endl;
    */

   get_path(dp, arr, n);

    cout << endl;

   return dp[0];
  

}



int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> dp(n+1,-1);
    
    for(int i=0; i<n ;i++){
        cin >> arr[i];
    }
    
    
  // cout<<  frog_reculsion(0,n, arr);
  
 //cout << frog_Jump(0,n, arr, dp); // memorazation
 
cout<< frogJUMP(n, arr) ; // reculsive tebulation 


    
    
    
    

    return 0;
}
