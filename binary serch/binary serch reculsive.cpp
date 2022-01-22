
#include <iostream>

using namespace std;

int bin_serch(int n, int a[], int low, int high, int key ){
    
    if(high >= low){
        
        int mid = (low+high)/2;
    
        if(a[mid] == key){
         return mid;
        }
        else if(a[mid] < key){
            bin_serch(n, a, mid+1, n-1, key);
        }
        else if(a[mid] > key){
            bin_serch(n,a,0,mid-1,key);
        }
    }
    
    return -1;
    
    
}

int main()
{
    int n;
    cin >>n;
    int arr[n];
    
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    int key;
    cin >> key;
    
    cout<< bin_serch(n, arr, 0 ,n-1, key);

    return 0;
}
