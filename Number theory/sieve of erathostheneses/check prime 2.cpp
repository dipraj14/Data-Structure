/*
 factor of 36....
 36 = 1 * 36
      2* 18
      3* 12
      4* 9
      6* 6
    ...............
      9* 4 
      12* 3   // this is repeated
      18* 2
      36* 1   

*/
/*
 #include<bits/stdc++.h>
using namespace std;


int main(){
    int cnt = 0;
    int n;
    cin >> n;
    for(int i=1; i<=sqrt(n);i++){   // for loop take o(sqrt(n)) but every time check this ....and sqrt(n) takes log(n) time 
                                    // so overall time compilxity ---- o(log n * sqrt(n))

        if(n %i == 0){
            cnt ++;
            if((n/i) != i){
            cnt++;
             }
        }
        

    }

    if(cnt == 2){
        cout<< "yes" <<endl;
    }
    else{
        cout<< "NO" <<endl;
    }
}

*/

#include<bits/stdc++.h>
using namespace std;


int main(){
    int cnt = 0;
    int n;
    cin >> n;
    for(int i=1; i*i<=n;i++){   // for loop take o(sqrt(n)) if we write i*i<=n  
                                    // so overall time compilxity ---- o( sqrt(n))

        if(n %i == 0){
            cnt ++;
            if((n/i) != i){
            cnt++;
             }
        }
        

    }

    if(cnt == 2){
        cout<< "yes" <<endl;
    }
    else{
        cout<< "NO" <<endl;
    }
}