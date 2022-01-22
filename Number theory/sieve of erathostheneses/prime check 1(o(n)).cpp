#include<bits/stdc++.h>
using namespace std;


int main(){
    int cnt = 0;
    int n;
    cin >> n;
    for(int i=1; i<=n;i++){   // this take o(n) ....

        if(n %i == 0){
            cnt ++;
        }

    }

    if(cnt == 2){
        cout<< "yes" <<endl;
    }
    else{
        cout<< "NO" <<endl;
    }
}