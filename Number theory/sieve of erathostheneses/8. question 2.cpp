/*

you have given Q quries , each quries have l and r, count no of primes between l to r.

input:
 
 3
 2 7
 10 20
 5 15

 output:
 4
 4
 3

 constrains:
 Q<= 10^6
 1<= l,r <=10^6 
 1<=n<=10^6

 */

//  here if i use sieve then --- O( Q* (r-l) + o(nlog(log(n)) ) = 10^6 * 10^6 = 10^12 operation ... it will not run in 1 sec


#include<bits/stdc++.h>
using namespace std;


int N =1000000;                 
                               
int sieve[1000001];
void createSieve(){
    for(int i=2; i<=N ;i++){
        sieve[i] = 1;
    }
    for(int i=2;i*i<=N;i++){
        if(sieve[i] == 1){
            for(int j=i*i ; j<=N ;j = j+i){
                sieve[j] = 0;
            }
        }
    }
   
}


 int main(){

    
   
    createSieve();     // sieve takes o(n log(log n))
    int prefix[N+1] ;
    prefix[0] = 0;
    prefix[1] = 0;
    for(int i=2; i<=N; i++){                         // prefix takes o(n)
        prefix[i] = prefix[i-1] + sieve[i];
    }

   
                                        // overall = o(Q)*O(1) + o(n) + o(n log(log n))  aprox 10^6  = its runs 1 sec
    int q;
    cin >> q;
    while(q--){     // 0(q)

        int l;
        int r;
        cin >> l >> r;  // 2 4

        int ans =  prefix[r];   // o(1)      
        if(l>0){
            ans -=prefix[l-1];
        }
        cout<< ans <<endl;
    }
    
        


   
}