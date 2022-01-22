/*

#include<bits/stdc++.h>
using namespace std;


int main(){

   int n;
   cin >> n;
    for(int i=2; i<=n ;i++){   // o(N)
        while(n% i == 0){
            cout<< i<< " ";
            n = n/i;
        }
        
    }
}
*/

/*
#include<bits/stdc++.h>
using namespace std;


int main(){

   int n;
   cin >> n;
    for(int i=2; i*i<=n ;i++){   // o(sqrt(n))   //
        while(n% i == 0){
            cout<< i<< " ";
            n = n/i;
        }
        
    }

    if(n>1){   // if no is not divide by sqrt(n) then number itself is prime
        cout<< n ;
    }
}
*/


/*
question : you have given Q quries, each quries you given n . your task is print all the prime factor of 2 to n,

input:       constarains:
               1<= Q <= 10^6 , 1<=N<=10^6
3
100 
25
13

output:

2 2 5 5 
5 5
13

*/

// here if i use suqure root of n time use prime factorization then it will not work because

//   o(sqrt(n) * Q) = 10^3 * 10^6 = 10^9 time it takes ...so its dose'nt run with in 1sec.....



#include<bits/stdc++.h>

using namespace std;

int N =1000000;                 
                               
int spf[1000001];
void create_SPF(){
    for(int i=2; i<=N ;i++){
        spf[i] = i;
    }
    for(int i=2;i*i<=N;i++){
        if(spf[i] == i){
            for(int j=i*i ; j<=N ;j = j+i){
                spf[j] = i;
            }
        }
    }
   
}
int main(){

    int q;
    cin >>q;
    while(q--){
         create_SPF();
        int n;cin>> n;

         while(n != 1){

            cout<< spf[n] <<" ";
            n = n/spf[n];

        }
        cout<< endl;
    }
   

}
