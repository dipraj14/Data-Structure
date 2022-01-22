

// leet code dp



/*
#include<bits/stdc++.h>
using namespace std;



int house_robbing(int n,int flag, vector<int> &v, vector<vector<int>> &dp){  // n-1 to 0 reculsive

    

	if(n == 0){
		return 0;
	}
    if(dp[n][flag] != -1){
        return dp[n][flag];
    }

   int maxi = INT_MIN;

	if(flag == 0){
		maxi = max(v[n-1]+ house_robbing(n-1, 1, v,dp), house_robbing(n-1, 0, v,dp));
	}
	else{

		maxi = house_robbing(n-1, 0, v,dp);
	}

    return dp[n][flag] = maxi;

  
}
int main(){


	int n;
	cin >> n;

    vector<int> v(n);

    for(int i=0; i<n;i ++){
        cin >> v[i];
    }

   vector<vector<int>> dp(n+1,vector<int> (2,-1));


	cout<< house_robbing(n, 0, v, dp);

}

*/


/*

#include<bits/stdc++.h>
using namespace std;



int house_robbing(int n,vector<int> &v){  // 0-n

     vector<vector<int>> dp(n+1,vector<int> (2));

     dp[0][0] = 0;
     dp[0][1] = 0;

     for(int i= 1 ;i <=n ;i++){

         dp[i][0] = max (v[i-1] + dp[i-1][1], dp[i-1][0]);
         dp[i][1] = dp[i-1][0];
     }


     return max(dp[n][1], dp[n][0]);
   

  
}
int main(){


	int n;
	cin >> n;

    vector<int> v(n);

    for(int i=0; i<n;i ++){
        cin >> v[i];
    }

  


	cout<< house_robbing(n, v);

}

*/





#include<bits/stdc++.h>
using namespace std;

int house_robbing(int idx,int flag, vector<int> &v, vector<vector<int>> &dp, int n){  // in this code 0 - n reculsion failed  // get tle 

    
    
	if(idx == n){
		return 0;
	}
    if(dp[idx][flag] != -1){
        return dp[idx][flag];
    }

   int maxi = INT_MIN;

   	if(flag == 0){
		maxi = max(v[idx]+ house_robbing(idx+1, 1, v, dp, n), house_robbing(idx+1, 0, v,dp, n));
	}
	else{
 
		maxi = house_robbing(idx+1, 0, v,dp, n);
	}

   

    return dp[idx][flag] = maxi;

  
}
int main(){


	int n;
	cin >> n;

    vector<int> v(n);

    for(int i=0; i<n;i ++){
        cin >> v[i];
    }

   vector<vector<int>> dp(n+1,vector<int> (2,-1));


	cout<< house_robbing(0, 0, v, dp, n);

}





/*

#include<bits/stdc++.h>
using namespace std;



int house_robbing(int n,vector<int> &v){  // n-1 to 0

     vector<vector<int>> dp(n+1,vector<int> (2));

     dp[n][0] = 0;
     dp[n][1] = 0;

     for(int i= n-1 ;i >=0 ;i--){
         dp[i][0] = max (v[i] + dp[i+1][1], dp[i+1][0]);
         dp[i][1] = dp[i+1][0];
     }


     return max(dp[0][1], dp[0][0]);
   

  
}
int main(){


	int n;
	cin >> n;

    vector<int> v(n);

    for(int i=0; i<n;i ++){
        cin >> v[i];
    }

  


	cout<< house_robbing(n, v);

}

*/