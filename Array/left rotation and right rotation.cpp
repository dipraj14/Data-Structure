
#include <bits/stdc++.h>

using namespace std;


// rotation ---- o(k*n)
void rotation(int a[], int n, int k){ // k=2

    while(k--) { // 2 1 

        int temp = a[0]; //1 2
        for ( int j = 0; j < n; j++)
        {
            a[j] = a[j+1]; // 2 3 4 5 5 // 3 4 5 1 1 
        }

        a[n-1] = temp ; // 2 3 4 5 1 // 3 4 5 1 2
        
    }
}

int main(){

    int n;
    cin >> n;

    int arr[n];

    for(int i =0; i<n; i++){
        cin >> arr[i];
    }
   int k;
   cin >> k;
    rotation(arr, n, k);

    for(int i=0;i<n;i++){
        cout<< arr[i] <<" ";
    }
}

// optimal ---> o(n)

/*
#include <bits/stdc++.h>
using namespace std;

void rev(int arr[], int n,int left, int right){
    
    while(left< right){
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    
}

void right_Rotate(int a[],int n,int k){
    
    k = k%n;
    
    rev(a,n,0,n-1);
    rev(a,n,0,k-1);
    rev(a,n,k,n-1);
    
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    
}




int main() {
   
    
    int n;
    cin>>n;
  
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k;
    cin>>k;
    right_Rotate(a,n,k);
    return 0;
}

*/

/*
#include <bits/stdc++.h>
using namespace std;
void rev(int arr[], int n,int left, int right){
    
    while(left< right){
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    
}
void left_Rotate(int a[],int n,int k){
    
    k = k%n;
    
    rev(a,n,0,n-1);
    rev(a,n,0,n-k-1);
    rev(a,n,n-k,n-1);
    
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    
}
int main() {
   
    
    int n;
    cin>>n;
  
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k;
    cin>>k;
    left_Rotate(a,n,k);
    return 0;
}
*/


