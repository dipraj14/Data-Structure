// print all the prime 

// you have print all the prime no from l to r
// 1<= l,r <=10^6 , 1<=n<=10^6, t<=10^6

#include<bits/stdc++.h>
using namespace std;


int N =1000000;                 // o(r-l)*1 + o(n log(log n)) = 10^6(log(log 10^6)) = 778151 aprox 10^7  .. it should be run  in 1 sec
                               
bool sieve[1000001];
void createSieve(){
    for(int i=2; i<=N ;i++){
        sieve[i] = true;
    }
    for(int i=2;i*i<=N;i++){
        if(sieve[i] == true){
            for(int j=i*i ; j<=N ;j = j+i){
                sieve[j] = false;
            }
        }
    }
   
}

void print_prime(int l, int r){
    for(int i=l; i<=r ; i++){
        if(sieve[i] == true){
            cout<< i<<" ";
        }
        
    }
    cout<< endl;
}
 int main(){

    
   
    createSieve();
  
        int l;
        int r;
        cin >> l >> r;

        print_prime(l,r);

   
}

// if we use sqrt(n) to check prime then it take o(r-l)*o(sqrt(n))