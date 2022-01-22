/*

check n is prime or not

first line contains t test cases (1<= t<= 10^6)

next line take n (1<= n<= 10^6)

*/
// assume we use sqrt(n) to check prime no then   code complixity will be o(t*sqrt(n)) = 10^6 * 10^3 = 10^9 != 10^8 
// your code is run in 1 sec....

// https://codeforces.com/problemset/problem/1294/C


// sieve algorithm

#include<bits/stdc++.h>
using namespace std;


int N =1000000;                 // o(n log(log n)) = 10^6(log(log 10^6)) = 778151 aprox 10^7  .. it should be run  in 1 sec
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
 int main(){

    
    int t;
    cin  >> t;
    createSieve();
    while(t--){
        int n;
        cin >> n;

        if(sieve[n] == true){
            cout<< "YES" << endl;
        }
        else{
            cout<< "NO";
        }
    }
}