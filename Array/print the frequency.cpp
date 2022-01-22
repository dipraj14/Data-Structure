#include <iostream>

using namespace std;

int main()
{
   int n;
    cin >> n;

    int arr[n];

    for(int i =0; i<n; i++){  //  0 1 2 2 3 4
        cin >> arr[i];
    }
  
    int N = 1e5+2;
    
    int freq[N];
    
    for(int i=0 ;i <N;i++){
        freq[i] = 0;
    }
    
    for(int i=0; i<n; i++){  // 0 1 2 3 4 5 6 ... index
        freq[arr[i]]++;        // 1 1 2 1 1 0 0 ... val
    }
    
    for(int i=0 ;i<N ;i++){
        if(freq[i] >=1 ){
            cout<< i <<"-"<< freq[i] <<endl;
        }
    }
    
    
}