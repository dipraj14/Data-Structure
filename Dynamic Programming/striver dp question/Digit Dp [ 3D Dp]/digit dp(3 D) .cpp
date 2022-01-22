
// Ques : compute the total no numbers in the range L to R such that the digit D occurs K times
/*
ex - L =8 R= 22 D=2 K= 1
output:
3

*/

/*
constrains --> 
0<= L < = RE <= 10^18
*/


#include<bits/stdc++.h>
using namespace std;

int brute(string l, int d, int k){
    int cnt =0;
    for(int i=0; i<l.length() ;i++){

        if(l[i] -'0' == d){
            cnt++;
        }

    }
    return cnt;
}
/*
int f ( int idx, bool flag, string N, int cnt, int d, int k){  // using reculsion   // tc--> o(10^18) for generate each state and digit loop takes 10 total --> 0(10^18 * 10) = 0(10^19)

        if(idx == N.size()){
            return cnt == k;
        }

        int limit = N[idx] - '0';
        if(flag == true){
            limit = 9;
        }
        int ans = 0;
        for(int digit=0; digit<= limit; digit++){

            if(digit < N[idx] - '0'){
                if(digit == d){
                    ans += f(idx+1, true, N, cnt+1, d, k);
                }
                else{
                    ans += f(idx+1, true, N, cnt, d, k);
                }
            }

            else{
                if(digit == d){
                    ans += f(idx+1, flag, N, cnt+1, d, k);
                }
                else{
                    ans += f(idx+1, flag, N, cnt, d, k);
                }
            }
        }


        return ans;



   

}
*/
int dp[18][2][18];
int f_Dp ( int idx, bool flag, string N, int cnt, int d, int k){  // using dp memo // // tc--> o(18 * 2 *18) for dp size and digit loop takes 10 total --> 0(18 * 2 *18 * 10) 

        if(idx == N.size()){
            return cnt == k;
        }

        if(dp[idx][flag][cnt] != -1){
            return dp[idx][flag][cnt];
        }

        int limit = N[idx] - '0';
        if(flag == true){
            limit = 9;
        }
        int ans = 0;
        for(int digit=0; digit<= limit; digit++){

            if(digit < N[idx] - '0'){
                if(digit == d){
                    ans += f_Dp(idx+1, true, N, cnt+1, d, k);
                }
                else{
                    ans += f_Dp(idx+1, true, N, cnt, d, k);
                }
            }

            else{
                if(digit == d){
                    ans += f_Dp(idx+1, flag, N, cnt+1, d, k);
                }
                else{
                    ans += f_Dp(idx+1, flag, N, cnt, d, k);
                }
            }
        }


        return dp[idx][flag][cnt] = ans;



   

}


void solve (string l, string r, int d, int k){   // 0 1 

    //vector<vector<vector<int> > > dp(r.size()+1, vector<vector<int>> (2, vector<int> (r.size()+1, -1)));
    memset(dp, -1 , sizeof(dp));
    
    int R = f_Dp(0, false, r , 0, d, k);

    memset(dp, -1 , sizeof(dp));

    int  L = f_Dp(0, false, l , 0, d, k ) ;

    int for_L =  brute(l, d, k);

    cout<< R - L + for_L;

}
int main(){

    string l , r;
    cin >> l >> r;

    int d, k;
    cin >> d >> k;

    solve(l,r, d, k);

}
