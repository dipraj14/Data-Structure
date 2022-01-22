

// https://leetcode.com/problems/jump-game/submissions/

#include <iostream>

using namespace std;

int main()
{
    int maxi = 0;
    
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >>arr[i];
    }
    
    int flag = 1;
    
    for(int i=0; i<n;i++){
        if(maxi < i){
            flag = 0;
        }
            
        maxi  = max(maxi, i+ arr[i]);
        
          
    }
    
    if(flag ==1){
        cout << "true";
    }
    else{
        cout <<"false";
    }

    return 0;
}
