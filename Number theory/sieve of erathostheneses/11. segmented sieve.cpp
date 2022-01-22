#include<bits/stdc++.h>
using namespace std;

void segmented_sieve(){
 
        int l;
        int r;
        cin >> l >> r;

        // 
     
        int N = sqrt(r);

        bool sieve[N+1];

        for(int i=1; i<= N;i++){
            sieve[i] = true;
        }

        for(int i =2; i*i<=N ;i++){
            if(sieve[i] == true){
                for(int j=i*i;j<=N;j+=i){
                    sieve[j] = false;
                }
            }
        }
       // step1: generate prime till sqrt(n)
        vector<int> prime;

        for(int i=2;i<=N;i++){
            if(sieve[i] == true){
                prime.push_back( i);
            }
        }
        /*for(auto x: prime){
            cout<< x<<" ";
        }
        */
        int size = r-l;
        bool mark[size];
    
        for(int i=0;i<=size;i++){
            mark[i] = true;
        }
        
        // sptep 2: mark all prime multiple given l to r
        for(auto pr: prime){

            int firstmiltipale = (l/pr)*pr;
            if(firstmiltipale < l){
                firstmiltipale+=pr;
            }
            
            
            // in case of 11 you will get firstmiltipale is 110 but you need to take 11*11
            for(int i=max(pr*pr, firstmiltipale) ;i<=r; i+=pr){
                // 110 - 0   (110 -110)
                // 111 = 1   (111-110)
                // 112 - 2  (112 - 110)
                mark[i-l] = false;

            }
          
        }
        
         
        /*for(int i=0;i<=size;i++){
            cout<< mark[i]<<" ";
        }*/
        
       /*countprime between l to r
       int cnt = 0;
        
        for(int i=l;i<=r ;i++){
            if(mark[i-l] == 1){
                cnt++;
            }
        }
        
        cout << cnt <<endl;
        */
       // print prime between l to r
       vector<int> ans;
       for(int i=l;i<=r ;i++){
            if(mark[i-l] == 1){
                ans.push_back(l+(i-l));
            }
        }
        for(auto x: ans){
            cout<< x<< " ";
        }
        


   
}

int main(){
    
   segmented_sieve();

}
