// https://atcoder.jp/contests/dp/tasks/dp_c
/*

#include<bits/stdc++.h>
using namespace std;



int vacnation(int idx,int flag, vector<int> &a,vector<int> &b, vector<int> &c, vector<vector<int>> &dp, int n){  // in this code 0 - n reculsion failed  // get tle 

    
    if(idx == n){                 // 0 to n-1 reculsion 
        return 0;
    }
	
   

   int maxi = INT_MIN;

   if(flag == 0){
       int firsttask = a[idx] + vacnation(idx+1, 1, a, b, c, dp, n);
       int secondtask = b[idx] + vacnation(idx+1, 2, a, b, c, dp, n);
       int thirdtask = c[idx] + vacnation(idx+1, 3, a, b, c, dp, n);

       maxi = max({firsttask, secondtask, thirdtask});
   }
   else if(flag == 1){
      
       int secondtask = b[idx] + vacnation(idx+1, 2, a, b, c, dp, n);
       int thirdtask = c[idx] + vacnation(idx+1, 3, a, b, c, dp, n);

       maxi = max({ secondtask, thirdtask});
   }
   else if(flag == 2){
       int firsttask = a[idx] + vacnation(idx+1, 1, a, b, c, dp, n);
       
       int thirdtask = c[idx] + vacnation(idx+1, 3, a, b, c, dp, n);

       maxi = max({firsttask,  thirdtask});
   }
   else{

        int firsttask = a[idx] + vacnation(idx+1, 1, a, b, c, dp, n);
       int secondtask = b[idx] + vacnation(idx+1, 2, a, b, c, dp, n);
      

       maxi = max({firsttask, secondtask});

   }

   return maxi;



	
  
}
int main(){


	int n;
    cin>>n;
    vector<int> a(n), b(n), c(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i]>> b[i] >> c[i];
    }

   vector<vector<int>> dp(n+1,vector<int> (4,-1));


	cout<< vacnation(0, 0, a,b,c, dp, n);

}

*/


/*
#include<bits/stdc++.h>
using namespace std;



int vacnation(int idx,int flag, vector<int> &a,vector<int> &b, vector<int> &c, vector<vector<int>> &dp, int n){  // in this code 0 - n reculsion failed  // get tle 

    
    if(idx == n){                 // 0 to n-1 reculsion  using dp ------> [memorazation ]
        return 0;
    }

    if(dp[n][flag] != -1){
        return dp[n][flag];
    }
	
   

   int maxi = INT_MIN;

   if(flag == 0){
       int firsttask = a[idx] + vacnation(idx+1, 1, a, b, c, dp, n);
       int secondtask = b[idx] + vacnation(idx+1, 2, a, b, c, dp, n);
       int thirdtask = c[idx] + vacnation(idx+1, 3, a, b, c, dp, n);

       maxi = max({firsttask, secondtask, thirdtask});
   }
   else if(flag == 1){
      
       int secondtask = b[idx] + vacnation(idx+1, 2, a, b, c, dp, n);
       int thirdtask = c[idx] + vacnation(idx+1, 3, a, b, c, dp, n);

       maxi = max({ secondtask, thirdtask});
   }
   else if(flag == 2){
       int firsttask = a[idx] + vacnation(idx+1, 1, a, b, c, dp, n);
       
       int thirdtask = c[idx] + vacnation(idx+1, 3, a, b, c, dp, n);

       maxi = max({firsttask,  thirdtask});
   }
   else{

        int firsttask = a[idx] + vacnation(idx+1, 1, a, b, c, dp, n);
       int secondtask = b[idx] + vacnation(idx+1, 2, a, b, c, dp, n);
      

       maxi = max({firsttask, secondtask});

   }

   return dp[idx][flag] =  maxi;



	
  
}
int main(){


	int n;
    cin>>n;
    vector<int> a(n), b(n), c(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i]>> b[i] >> c[i];
    }

   vector<vector<int>> dp(n+1,vector<int> (4,-1));


	cout<< vacnation(0, 0, a,b,c, dp, n);

}
*/


/*

#include<bits/stdc++.h>
using namespace std;



int vacnation(vector<int> &a,vector<int> &b, vector<int> &c,  int n){  

    
    
	vector<vector<int>> dp(n+1,vector<int> (4));   // n-1 to  0 itrative 
   

   

  for(int i=0;i <=3; i++){
      dp[n][i] = 0;
  }

   for(int i=n-1; i>=0;i--){

       dp[i][0] = max ({a[i] + dp[i+1][1], b[i]+ dp[i+1][2], c[i]+ dp[i+1][3]}) ;

       dp[i][1] = max ( b[i]+ dp[i+1][2], c[i]+ dp[i+1][3]);

       dp[i][2] = max (a[i] + dp[i+1][1], c[i]+ dp[i+1][3]);

      dp[i][3] =  max (a[i] + dp[i+1][1], b[i]+ dp[i+1][2]);

       

   }

   return max({dp[0][0], dp[0][1], dp[0][2], dp[0][3]});

   



	
  
}
int main(){


	int n;
    cin>>n;
    vector<int> a(n), b(n), c(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i]>> b[i] >> c[i];
    }

   


	cout<< vacnation( a,b,c, n);

}


*/





// https://atcoder.jp/contests/dp/tasks/dp_c



#include<bits/stdc++.h>
using namespace std;



int vacnation(int idx,int flag, vector<int> &a,vector<int> &b, vector<int> &c, vector<vector<int>> &dp, int n){  

    
    if(idx == 0){                 // reculsion n-1 to 0
        return 0;
    }
	
    if(dp[n][flag] != -1){
        return dp[n][flag];
    }
	

   int maxi = INT_MIN;

   if(flag == 0){
       int firsttask = a[idx-1] + vacnation(idx-1, 1, a, b, c, dp, n);
       int secondtask = b[idx-1] + vacnation(idx-1, 2, a, b, c, dp, n);
       int thirdtask = c[idx-1] + vacnation(idx-1, 3, a, b, c, dp, n);

       maxi = max({firsttask, secondtask, thirdtask});
   }
   else if(flag == 1){
      
       int secondtask = b[idx-1] + vacnation(idx-1, 2, a, b, c, dp, n);
       int thirdtask = c[idx-1] + vacnation(idx-1, 3, a, b, c, dp, n);

       maxi = max({ secondtask, thirdtask});
   }
   else if(flag == 2){
       int firsttask = a[idx-1] + vacnation(idx-1, 1, a, b, c, dp, n);
       
       int thirdtask = c[idx-1] + vacnation(idx-1, 3, a, b, c, dp, n);

       maxi = max({firsttask,  thirdtask});
   }
   else{

        int firsttask = a[idx-1] + vacnation(idx-1, 1, a, b, c, dp, n);
       int secondtask = b[idx-1] + vacnation(idx-1, 2, a, b, c, dp, n);
      

       maxi = max({firsttask, secondtask});

   }

   return dp[idx][flag] =  maxi;



	
  
}
int main(){


	int n;
    cin>>n;
    vector<int> a(n), b(n), c(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i]>> b[i] >> c[i];
    }

   vector<vector<int>> dp(n+1,vector<int> (4,-1));


	cout<< vacnation(n, 0, a,b,c, dp, n);

}
