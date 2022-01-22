#include <bits/stdc++.h>
using namespace std;
 

int count_subset(int set[], int n, int sum)
{
	int dp[n+1][sum+1];

    for(int i=0; i<=n; i++){
        dp[i][0] = 1;
    }
    for(int j=1; j <=sum; j++){
        dp[0][j] = 0;
    }

   for(int i=1; i<=n; i++){
       for(int j=1; j <=sum; j++){
           
           if(set[i-1] > j){
               dp[i][j] = dp[i-1][j];
           }
           else{
               dp[i][j] = dp[i-1][j] + dp[i-1][ j - set[i-1] ];
           }
       }
   }

   return dp[n][sum];
	

}
 

void starter(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}


int main()
{

    //starter();
    int n;
    cin >>n;
    
    int diff;
    int set[n];
    for(int i=0;i<n;i++){
        cin >> set[i];
    }

    cin >> diff;

    int sum =0;
    for(int i=0;i<n;i++){
        sum += set[i];
    }

    int s1 = (diff + sum)/2;    // first   s1 - s2 = diff
                                // second  s1 + s2 = sum(arr)
                                //         so, s1 = ( sum(arr) + diff )/2
                                // if we found no. possible s1 then we found the number of subset with a given difference.... 

    cout <<" the number of subset with a given difference is : "<< count_subset(set,n,s1);

    
    return 0;
}