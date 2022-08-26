// #include<bits/stdc++.h>
// using namespace std;

// void segmented_sieve(){
 
//         int l;
//         int r;
//         cin >> l >> r;

//         // 
     
//         int N = sqrt(r);

//         bool sieve[N+1];

//         for(int i=1; i<= N;i++){
//             sieve[i] = true;
//         }

//         for(int i =2; i*i<=N ;i++){
//             if(sieve[i] == true){
//                 for(int j=i*i;j<=N;j+=i){
//                     sieve[j] = false;
//                 }
//             }
//         }
//        // step1: generate prime till sqrt(n)
//         vector<int> prime;

//         for(int i=2;i<=N;i++){
//             if(sieve[i] == true){
//                 prime.push_back( i);
//             }
//         }
//         /*for(auto x: prime){
//             cout<< x<<" ";
//         }
//         */
//         int size = r-l;
//         bool mark[size];
    
//         for(int i=0;i<=size;i++){
//             mark[i] = true;
//         }
        
//         // sptep 2: mark all prime multiple given l to r
//         for(auto pr: prime){

//             int firstmiltipale = (l/pr)*pr;
//             if(firstmiltipale < l){
//                 firstmiltipale+=pr;
//             }
            
            
//             // in case of 11 you will get firstmiltipale is 110 but you need to take 11*11
//             for(int i=max(pr*pr, firstmiltipale) ;i<=r; i+=pr){
//                 // 110 - 0   (110 -110)
//                 // 111 = 1   (111-110)
//                 // 112 - 2  (112 - 110)
//                 mark[i-l] = false;

//             }
          
//         }
        
         
//         /*for(int i=0;i<=size;i++){
//             cout<< mark[i]<<" ";
//         }*/
        
//        /*countprime between l to r
//        int cnt = 0;
        
//         for(int i=l;i<=r ;i++){
//             if(mark[i-l] == 1){
//                 cnt++;
//             }
//         }
        
//         cout << cnt <<endl;
//         */
//        // print prime between l to r
//        vector<int> ans;
//        for(int i=l;i<=r ;i++){
//             if(mark[i-l] == 1){
//                 ans.push_back(l+(i-l));
//             }
//         }
//         for(auto x: ans){
//             cout<< x<< " ";
//         }
        


   
// }

// int main(){
    
//    segmented_sieve();

// }


// NEWLY WRITTEN CODE 


// T <= 10
// 1 <= (L, R) <= 10^12  
// R - L <= 10^6          // highest --> 10^ 6


// Print all the Prime number Between L - R Segmrnt 

#include <bits/stdc++.h>  // this will work only for 10^6 but pefixPrime() which was work upto 10^7 ----> impleting below

using namespace std;

const int N = 1000000;
bool sieve[N + 1];

void createSieve(){
    
    for(int i=2; i<= N; i++){
        sieve[i] = true;
    }
    
    for(int i=2; i * i <= N; i++){
        if(sieve[i] == true){
            for(int j = i * i ; j <= N; j+= i){
                sieve[j] = false ;
            }
        }
    }
    
}

vector<int> generateAllThePrimes(int n){  // 11 
    vector<int> ds;
    for(int i=2; i<= n; i++){  // 2 3 4 5 6 7 8 9 10 11 
        if(sieve[i] == true){
            ds.push_back(i);  // 2 3 5 7 11 
        }
    }
    
    return ds;
}

int main()
{
    createSieve();  // n log(log n)  --> o(n) --> 10^6
    
    int t;
    cin >> t;
    
    while(t--){
        int l, r;
        cin >> l >> r;  // 110 // 130

        // step 1 -> generate all the prime till Sqrt(r)...
        
        int sq = sqrt(r);
        // 10^ 6   --> o(n )
        vector<int> prime = generateAllThePrimes(sq);   // sqrt(130) = 11 // 2 3 5 7 11 --> prime 
   
   
        // step - 2 
        
        // create a dummy arry of size (R - L + 1) and make everyone with 1
        
        int dummy[r - l + 1];  // 21 
        // 10 ^ 6  // o(n )
        for(int i= 0; i< r -l + 1; i++){  //  1 1 1 1 1 1 1  1 1 1 1  // 0 - 21 
            dummy[i] = 1;
        }
        
        
        // step 3 -> 
        
        // for all the prime number which is store into the prime array , 
        // make its multiples as false 
        
        for(auto i: prime){  // 2 3 5 7 11     // o(sqrt(r)) // sqrt(10^6) --> 10^4
        
            int fastMultiple = (l / i) * i;  // 110   // 108
            
            if(fastMultiple < l) fastMultiple += i;  // 108 + 3  = 111 
            
            for(int j = max(fastMultiple, i * i); j <= r ; j += i){  // 110 (H) --> j   // 10^6 
                dummy[j - l] = 0; // (j - l) ---> 110 - 110 = 0 
            }
        }
        
        
        // over all ---> n log(log n) + o(n) + o(n)  + o(sqrt(r)) * o(R - L )
        
        // 10 ^ 6 + 10 * [ 10^ 6 + 10^6 +( 10 ^ 4 * 10 ^ 6 ) ]   -- 10 ^ 10 * 10 = 10 ^ 11 (approx)  <  10 ^ 12 
        
        
        // print 
        
        for(int i = l; i<=r; i++){  // 110 - > 0  // 111 - > 1 // 112 -> 2 //  
            if(dummy[i - l] == 1){
                cout << i <<" ";
            }
        }
    
        
    }


    return 0;
}





// Smae Question But better than Segmented Sive Concept and Easy to remember  ---> name ---> prefixPrime() -> 

#include <bits/stdc++.h>
using namespace std;

const int N = 1e7;
bool sieve[N + 1];
vector<int> prefixPrime(N + 1);


void createSieveAndCalculatePrefixPrime(){
    for(int i = 2; i<=N; i++){
        sieve[i] = 1;
    }
    
    for(int i = 2 ; i*i <=N; i++){
        if(sieve[i] == 1){
            for(int j = i * i ; j<=N; j+=i){
                if(sieve[j] != 0){
                    sieve[j] = 0;
                }
            }
        }
    }
    
    for(int i = 2; i<=N; i++){
        prefixPrime[i] = prefixPrime[i - 1] + sieve[i];
    }
    
}

int main() {
    
    createSieveAndCalculatePrefixPrime();
    int t;
    cin >> t;
    while(t--){
        int l , r;
        cin >> l >> r;
        cout << prefixPrime[r] - prefixPrime[ l - 1 ] << endl;
        
    }
	return 0;
}



