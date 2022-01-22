#include <iostream>
using namespace std;

void last_idx(int a[], int n, int x){

    int flag = -1;

    for(int i=n; i>=0; i--){
        if(x==a[i]){
            flag = i;
            break;
        }
    }
    cout<<flag;
}
int main() {
    
    int n;
    cin>> n ;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int x;
    cin>>x;

    last_idx(a, n, x);

    return 0;
}