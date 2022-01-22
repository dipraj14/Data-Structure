

#include <bits/stdc++.h>

using namespace std;

//int min_step = INT_MAX;

 int min_step = INT_MAX;
 int mod = 100000;

int max_step( int start,  int g_mul, int n,  int arr[], int dive){
    
    
   
    if(start > g_mul ){
        return 0;
    }
    if(start == g_mul){
        return 1;
    }
   
    
    for(int idx = 0; idx<n; idx++){
            
           // dive = (start * arr[idx]) / mod;
            
            start = (start * arr[idx]) ;//% mod;
            
           
   
           
                
               min_step = (min_step, 1+ max_step( start,  g_mul,  n, arr, dive) );
           
        
        //start = ( (mod * dive) + start) / arr[idx];
        start = start / arr[idx];
   
  
       
      
    }
    
    return min_step;
  
    
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n; i++){
        cin >> arr[i];
    }
    int s, e;
    cin >> s >> e;
    //int mul = s;
     cout << max_step(s,  e,  n, arr, 1);
     

    

    return 0;
}




/*

#include <bits/stdc++.h>

using namespace std;

int min_step = INT_MAX;

void max_step( int start,  int g_mul, int n,int cnt, int arr[]){
    
    
   
    if(start > g_mul ){
        return ;
    }
    if(start == g_mul){
        min_step = min(min_step, cnt);
        return ;
    }
   
    for(int idx = 0; idx<n; idx++){
        
            start = start * arr[idx];
     
            if(start <= g_mul){
                 max_step( start,  g_mul,  n,cnt +1, arr);
            }
        
        start = start / arr[idx];
   
  
       
      
    }
  
    
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n; i++){
        cin >> arr[i];
    }
    int s, e;
    cin >> s >> e;
    //int mul = s;
     max_step(s,  e,  n,0, arr);
     
     cout << min_step << endl;
    

    return 0;
}
*/