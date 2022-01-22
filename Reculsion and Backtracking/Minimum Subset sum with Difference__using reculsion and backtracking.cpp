
//Minimum Subset sum with Difference__using reculsion and backtracking (striver approch)

// To see the Dynamic Programming approach check Dynamic programming folder

#include <bits/stdc++.h>
using namespace std;
 

void isSubsetSum(int idx, int set[], int n,vector<int> &ds, vector<int> &v){
    
    int sum = 0;
    if(idx == n){
        for(auto x: ds){
            sum +=x;
        }
        
        v.push_back(sum);
        return;
    }
    
    ds.push_back(set[idx]);
    isSubsetSum(idx+1, set, n, ds, v);
    ds.pop_back();
    
     isSubsetSum(idx+1, set, n, ds, v);
    
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

   int idx = 0;
    vector<int> ds;
    
    vector<int> v;
    isSubsetSum(0,set, n, ds, v );
    
   
    sort(v.begin(),v.end());
    
    vector<int> s1;
    for(int j=0;j<v.size();j++){
        if(v[j] <= sum/2){
            s1.push_back(v[j]);
        }
    }
    
   
    

    
    int mini = INT_MAX;

    for(int i=0;i <= s1.size() ;i++){
        mini = min(mini, range-2*s1[i]);
    }


    cout<< mini <<endl;
   

   

    
    return 0;
}