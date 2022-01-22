
#include <iostream>

using namespace std;

void test(){
    
   int n;
    cin >> n;

    int arr[n];
    
    int flag =1;

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
        if(freq[i] > 1 ){
            flag = 0;
            break;
        }
    }
    
    if(flag == 1){
        cout << "prekrasnyy"<<endl;
    }
    else{
        cout << "ne krasivo"<<endl;
    }
}

int main()
{
    
    int t;
    cin >> t;
    
    for(int i=1;i<=t;i++){ 
        
        test();
    }
    
    
}
