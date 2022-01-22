#include <bits/stdc++.h>

using namespace std;

int lcs(int m,int n, string s1, string s2){
    
    // base case
    if(m==0 || n==0){
        return 0;
    }
    
    if(s1[m-1] == s2[n-1]){
        return 1+lcs(m-1,n-1,s1,s2);
    }
    else{
        int left = lcs(m-1, n, s1, s2); // left
        int right = lcs(m, n-1, s1, s2);  // right
        
        return max(left,right);
    }
    
    
    
}

int main()       // overall TC -> o(2^n)
{
   string s1 ;
   string s2 ;

   cin >> s1 >>s2;
   
   cout<<"LCS is: "<< lcs(s1.size(),s2.size(),s1,s2);

    return 0;
}