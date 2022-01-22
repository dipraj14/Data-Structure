

// if you understand question properly ---> https://www.youtube.com/watch?v=xFJXtB5vSmM


// https://www.youtube.com/watch?v=m-Dqu7csdJk    --- > code link this [Method 3]


// minimum element in all the window

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    vector<int> ans;
   /* int i = 0;
    int min_e  =INT_MAX;
    int cnt = 0;
    
    while(i <= n-1){  // o(n)
        
        min_e = min(a[i], min_e);
        //cout << min_e <<" ";                   // this is wrong 
        
      //  cout<< cnt + 1<<endl;
        if(cnt+1 == k){
            cnt = cnt-1;
            
            ans.push_back(min_e);
            min_e = INT_MAX;
            
        }
        
        i++;
        cnt++;
        
  
        
    }
    int max_e = INT_MIN;
    */
    
    std::deque<int> dq(k) ;
    
    int i;
    
    for(i= 0; i<k ;i++){
     
        while(!dq.empty() and a[i] <= a[dq.back()]){     // if next elemet is smaller than previous element,  then remove the previous one....
                                                          //  try to maintain incresing fassion
            dq.pop_back();
        }
        dq.push_back(i);
        
    }
  
    while(i < n){
        //cout << i <<" " << k <<" ";
        ans.push_back(a[dq.front()]);

        

        while(!dq.empty() and dq.front() <= i-k){
            dq.pop_front();
        }
        
        while(!dq.empty() and a[i] <= a[dq.back()]){
            dq.pop_back();
        }
        
        dq.push_back(i);
        
        i++;
    }
    
    ans.push_back(a[dq.front()]);
    
  
    
    for(auto it: ans){
        cout << it <<" ";                  
        
    }
    
    

    return 0;
}
