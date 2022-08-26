// Segmented Sieve Algo

// QUESTION -> // Print all the Prime number Between L - R Segmrnt 

// T <= 10
// 1 <= (L, R) <= 10^12  
// R - L <= 10^6          // highest --> 10^ 6

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
            if(dummy[i - l] == 1 && i != 1){  // i != 1 because 1 was not a prime number and 1 <= l thats why // 1 10 --> for this test case first number print 1 so i check i != 1
                cout << i <<" ";
            }
        }
    
        
    }


    return 0;
}





// Smae Question But better than Segmented Sive Concept and Easy to remember  ---> name ---> prefixPrime() ->
// 1 ≤ T ≤ 10^5
// 1 ≤ L ≤ 10^7
// 1 ≤ R ≤ 10^7   // this gives TLE if we implemented with Sigmented Sieve Algo 

// https://www.codechef.com/problems/CNTPRIME?tab=statement --> question ---> if we submite using Segment Sive Algo than it give TLE and Partilly Correct Ans
// BUT if we Submit USing PrefixPrime() is give correct ans 

// BUT PrefixPrime() uses only for count purpose --> not for Printing purpose
// Printing and count purpose -> Segmented Sieve algo (Both work)


#include <bits/stdc++.h>
using namespace std;

const int N = 1e7;
bool sieve[N + 1];
vector<int> prefixPrime(N + 1);


void createSieveAndCalculatePrefixPrime(){
    for(int i = 2; i<=N; i++){
        sieve[i] = 1;
    }
    
    for(int i = 2 ; i*i <=N; i++){   // O(n log(log N)) 
        if(sieve[i] == 1){
            for(int j = i * i ; j<=N; j+=i){
                if(sieve[j] != 0){
                    sieve[j] = 0;
                }
            }
        }
    }
    
    for(int i = 2; i<=N; i++){
        prefixPrime[i] = prefixPrime[i - 1] + sieve[i];  // (O(N)) 
    }
    
}

int main() {
    
    createSieveAndCalculatePrefixPrime();  // O(n log(log N)) + O(N)
    int t;
    cin >> t;
    while(t--){
        int l , r;
        cin >> l >> r;
        cout << prefixPrime[r] - prefixPrime[ l - 1 ] << endl;  // O(1)
        
    }
	
	// overAll --> O(n log(log N)) + O(N) + O(t * 1 ) 
	// ----------> //10^7 + 10^7 + 10^5 ----> its runs with it one second ....So better Run Time is Compare to Segmented Sieve
	return 0;
}



