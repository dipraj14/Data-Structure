#include <bits/stdc++.h>
using namespace std;
 
// tagget sum problem is same as " count the number of subset with a given difference " ......


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
    
    int g_sum;
    int set[n];
    for(int i=0;i<n;i++){
        cin >> set[i];
    }

    cin >> g_sum;

    int sum =0;
    for(int i=0;i<n;i++){
        sum += set[i];
    }

    int s1 = (g_sum + sum)/2;    

    cout <<" the number of subset after placing - and + singn : "<< count_subset(set,n,s1);

    
    return 0;
}