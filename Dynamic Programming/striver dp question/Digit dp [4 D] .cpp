

// count the no of numbers is range (L to R) where the fast digit is equal to last digit

#include<bits/stdc++.h>
using namespace std;

int brute(string l){
    int cnt =0;
    int lef = 0;

    int rig = l.size() - 1;

    while(lef <= rig){
        if(l[lef] == l[rig]){
            cnt ++;
        }
        lef++;
        rig--;
    }
    return cnt;
}
/*
int f ( int idx, bool flag, int fd, int ld, string N){  // using reculsion   // tc--> o(10^19)

          if(idx == N.size()){
            return fd == ld;
        }

    

        int limit = N[idx] - '0';
        if(flag == true){
            limit = 9;
        }
        int ans = 0;
        for(int digit=0; digit<= limit; digit++){

            if(digit < N[idx] - '0'){
                if(fd != 0){

                    ans+= f_Dp(idx+1,true, fd, digit, N );

                }
                else{
                    ans+= f_Dp(idx+1,true, digit, digit, N );

                }
            }
            else{
                if(fd != 0){
                    ans+= f_Dp(idx+1, flag , fd, digit, N );
                }
                else{
                    ans+= f_Dp(idx+1, flag, digit, digit, N );
                }
            }
        }


       
       return ans;



   

}
*/

int dp[18][2][10][10];
int f_Dp ( int idx, bool flag, int fd, int ld, string N){  // using dp memorazation

        if(idx == N.size()){
            return fd == ld;
        }

        if(dp[idx][flag][fd][ld] != -1){
             return dp[idx][flag][fd][ld];
        }

        int limit = N[idx] - '0';
        if(flag == true){
            limit = 9;
        }
        int ans = 0;
        for(int digit=0; digit<= limit; digit++){

            if(digit < N[idx] - '0'){
                if(fd != 0){

                    ans+= f_Dp(idx+1,true, fd, digit, N );

                }
                else{
                    ans+= f_Dp(idx+1,true, digit, digit, N );

                }
            }
            else{
                if(fd != 0){
                    ans+= f_Dp(idx+1, flag , fd, digit, N );
                }
                else{
                    ans+= f_Dp(idx+1, flag, digit, digit, N );
                }
            }
        }


     return dp[idx][flag][fd][ld] = ans;
       //return ans;



   

}


void solve (string l, string r){   // 0 1 

    //vector<vector<vector<int> > > dp(r.size()+1, vector<vector<int>> (2, vector<int> (r.size()+1, -1)));
    memset(dp, -1 , sizeof(dp));
    
    int R = f_Dp(0, false, r[0]-'0', r[r.size()-1]-'0', r);

    memset(dp, -1 , sizeof(dp));
    int L = f_Dp(0, false, l[0]-'0', l[l.size()-1]-'0', l);

    int for_L = brute(l);

    cout << R - L + for_L;


}
int main(){

    string l , r;
    cin >> l >> r;

    solve(l,r);

}
