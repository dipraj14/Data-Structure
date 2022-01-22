/*

YOU have q quries . Every qurie has a number n. tell  me how many number between (1 to 10^6) have minimum prime factorazation as n.

input :
2
2
11
output:

500000
20779        Constraints:
                1 ≤ T ≤ 10^5
                Prime number X where 2 ≤ X ≤ 10^6
*/

// question link:   https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-2/practice-problems/algorithm/ashu-and-prime-factors-4/
#include<bits/stdc++.h>

using namespace std;


int N =1000000;                 
                               
int spf[1000001];
int h[1000001];
void create_SPF(){
    for(int i=2; i<=N ;i++){
        spf[i] = i;
    }
    for(int i=1;i<=N;i++){
        h[i] = 1;
    }
    for(int i=2;i*i<=N;i++){
        if(spf[i] == i){
          
            for(int j=i*i ; j<=N ;j = j+i){
                if(spf[j] == j){
                     spf[j] = i;
                     h[i] += 1;

                }
               
            }
        }
    }
   
}
int main(){
    create_SPF();
    int q;
    cin >>q;
    while(q--){
        
        int n;cin>> n;

         
        
             cout<< h[n] <<endl;
         
    }
   

}
