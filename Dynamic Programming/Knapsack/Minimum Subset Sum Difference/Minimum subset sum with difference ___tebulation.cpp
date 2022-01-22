#include <bits/stdc++.h>
using namespace std;
 

vector<int> isSubsetSum(int set[], int n, int sum)
{
	
	bool dp[n + 1][sum + 1];

    vector<int> v;


	for (int i = 0; i <= n; i++){
		dp[i][0] = true;
	}

	
	for (int i = 1; i <= sum; i++){
		dp[0][i] = false;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if ( set[i - 1] <= j){

				dp[i][j] = (dp[i - 1][j] || dp[i - 1][j - set[i - 1]] );
			}
			else{

				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	

	 for(int j=0; j <=sum/2 ;j++){
         if(dp[n][j] == true){
             v.push_back(j);
         }
     }

     return v;

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

    int set[n];
    for(int i=0;i<n;i++){
        cin >> set[i];
    }
    int sum =0;
    for(int i=0;i<n;i++){
        sum += set[i];
    }

    int range = sum;

   
    
    vector<int> s1 = isSubsetSum(set, n, sum );

  

    int mini = INT_MAX;

    for(int i=0;i <= s1.size() ;i++){
        mini = min(mini, range-2*s1[i]);
    }


    cout<< mini <<endl;

   

    
    return 0;
}