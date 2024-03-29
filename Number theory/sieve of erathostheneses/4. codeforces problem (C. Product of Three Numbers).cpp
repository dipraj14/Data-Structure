// https://codeforces.com/problemset/problem/1294/C


#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin >> n;

    int a =n, b =n, c= n;

    for(int i=2; i*i<=n ;i++){
        if(n%i == 0){
            a= i;
            break;
        }
    }
  
    n = n/a;
    for(int i=2; i*i<=n ;i++){
        if(n%i == 0){
            if(i != a){
                b = min(b, i);
            }
            if((n/i) != i){
                if((n/i) != a){
                    b = min(b, (n/i));
                }
            }
              
        }
    }

    c = n/ b;

    if(a!=b && b!=c && a!=c && c>2){
        cout<< "YES"<<endl;
        cout << a<< " "<< b<<" "<< c << endl;
    }
    else{
        cout<< "NO"<<endl;
    }
}
 int main(){
    int t;
    cin  >> t;

    while(t--){
        solve();
    }
}

/*
Easy Solution 

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        int a =1, b =1, c =1;
        
        int org_n = n;
        
        for(int i=2; i * i <=n; i++){
            if(n % i == 0){
                a = i;
                break;
            }
        }
        n = n / a;
        for(int i = 2 ; i * i <= n; i++){
            if(n% i == 0 && i != a){
                b = i;
                break;
            }
        }
        
        c = org_n / (a * b);
        
        if(a!= b && b!= c && a != c && a!=1 && b!=1 && c!=1){
            cout << "YES" << endl;
            cout << a <<" " << b << " " << c <<endl ;
        }else{
            cout <<"NO" << endl;
        }
    }

    return 0;
}
*/
