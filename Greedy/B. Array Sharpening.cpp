
// https://codeforces.com/contest/1291/problem/B


/*
#include<bits/stdc++.h>
using namespace std;

#define int long long int




signed main(){

 int t;
 cin >>t;
 while(t--){

    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >>arr[i];
    }

    int s_idx = n-1;

    int end_idx = 0;

    for(int i=0; i<n; i++){
        if(arr[i] < i){
            s_idx = i-1;
            break;
        }
        

    }
    int j=0;
    for(int i= n-1; i>=0; i--){
        
        if(arr[i] < j){
            end_idx = i+1;
            break;
 
        }
        j++;
    

    }

    if( end_idx <= s_idx){
        cout<< "Yes" <<endl;
    }
    else{
        cout<< "No"<<endl;
    }



 }



}
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long int




signed main(){

 int t;
 cin >>t;
 while(t--){

    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >>arr[i];
    }

    int s_idx = n-1;

    int end_idx = 0;

    for(int i=0; i<n; i++){
        if(arr[i] >= i){
            s_idx = i;
          
        }
        else{
            break;
        }
        

    }
    int j=0;
    for(int i= n-1; i>=0; i--){
        
        if(arr[i] >= j){
            end_idx = i;
            
 
        }
        else{
            break;
        }
        j++;
    

    }

    if( end_idx <= s_idx){
        cout<< "Yes" <<endl;
    }
    else{
        cout<< "No"<<endl;
    }



 }



}