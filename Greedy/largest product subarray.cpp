#include<bits/stdc++.h>
using namespace std;



int largest_product_subarray(int arr[],int n){

    int maxi = 1;
    int mini= 1;
    int product = INT_MIN;

    for(int i=0; i<n; i++){

        if(arr[i] == 0){
            mini = 1;
            maxi=1;
           
            
        }

        else{

           

          int temp = maxi;

             maxi = max({arr[i],  maxi*arr[i] , mini*arr[i] });
            
             mini = min({ arr[i],  mini*arr[i], temp*arr[i] });
         
            

            if(maxi > product){
                product = maxi;
            }
        }

    }

    if(product == INT_MIN){
        return 0;
    }

    
    return product;
}

int main(){


    int n;
    cin >> n;

    int arr[n];

    for(int i=0;i<n;i++){
        cin >>arr[i];
    }

    cout<< largest_product_subarray(arr,n);


}