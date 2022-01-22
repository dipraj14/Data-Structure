#include<bits/stdc++.h>
using namespace std;


int main(){
    int cnt = 0;
    int n;
    cin >> n;

    int sum = 0;
    for(int i=1; i*i<=n;i++){   
                                    // so overall time compilxity ---- o(log n * sqrt(n))

        if(n %i == 0){
            sum += i;
            if((n/i) != i){
                sum+= (n/i);
             }
        }
        

    }

    cout << sum;
}