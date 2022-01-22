#include <bits/stdc++.h>

using namespace std;


void print_sub(int idx, int n, vector<int> &ds, int arr[]){
    
    if(idx == n ){
        for(auto it: ds){
            cout<< it<<" ";   // 1 2 3 
        }
        cout<< endl;
        return;
    }
    
    ds.push_back(arr[idx]);  
    print_sub(idx+1, n , ds, arr); 
    
    ds.pop_back();
    print_sub(idx+1, n , ds, arr);
    
}


int main()
{
    int n;
    cin >> n;
    
    int arr[n];
    
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    vector<int> ds ;
    
    print_sub(0, n ,ds, arr);

    return 0;
}