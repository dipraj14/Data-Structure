
#include <iostream>

using namespace std;

int bin_serch(int n, int a[], int low, int high, int key ){
    
    while(high >= low){
        
        int mid = (low+high)/2;
    
        if(a[mid] == key){
         return mid;
        }
        else if(a[mid] < key){
            low = mid+1;
        }
        else if(a[mid] > key){
           high = mid-1;
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
