// question link :  https://codeforces.com/problemset/problem/1097/B

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int a[n];

    for(int i =0; i<n; i++){  
        cin >> a[i];
    }
    
   
   int flag =0;
   for(int i=0 ;i <(1<<n) ; i++){
       
       int sum =0;
       
       for(int bit =0; bit<n ; bit++){
           if(i & (1<<bit)){
               sum +=a[bit];
           }
           else{
               sum -=a[bit];
           }
       }
       if(sum == 0 || sum%360 == 0){  // sum%360 == 0 this is for 120 120 120 = + all the value gives 360%360 = 0
           flag =1 ;
           break;
       }
   }
   
   if(flag ==0){
       cout <<"NO"<<endl;
   }
   else{
       cout << "yes" <<endl;
   }
   

    return 0;
}
