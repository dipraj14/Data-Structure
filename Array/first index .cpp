

#include <iostream>

using namespace std;

int main()
{
  int n;
   cin >> n;
   
   int a[n];
   
   for(int i=0;i < n;i++){
       cin >> a[i];
   }
   
   int x;
   cin >> x;
   
   int flag =-1;
   
   for(int i=0;i < n;i++){
       if(a[i] == x){
           
           flag = i;
           break;
       }
   }
   
   cout<< flag <<endl;

    return 0;
}
