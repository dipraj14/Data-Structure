

// https://www.spoj.com/problems/NUMTSN/ 

// 369 number

#include<bits/stdc++.h>
using namespace std;

int brute(string l){
    int cnt3 =0;
    int cnt6 = 0;
    int cnt9 = 0;
    int lef = 0;

    while(lef < l.size()){
        if(l[lef] == '3'){
            cnt3++;

        }
        else if(l[lef] == '6'){
            cnt6++;
        }
        else if(l[lef] == '9'){
            cnt9++;
        }
        lef ++;

    }
   if( (cnt3 == cnt6) && (cnt6 == cnt9) && cnt3 != 0 && cnt6!= 0 && cnt9!=0){
       return 1;
   }
   else{
       return 0;
   }
}

int dp[51][2][17][17][17];
//dp[idx][flag][cnt3][cnt6][cnt9]
int f_Dp ( int idx, bool flag, string N, int cnt3, int cnt6, int cnt9){  // using dp memorazation

        if(cnt3 > N.size()/3 || cnt6 > N.size()/ 3 || cnt6> N.size()/3 || cnt9>N.size()){
            return 0;
        }

        if(idx == N.size()){
            return (cnt3 >= 1) && (cnt3 == cnt6) && (cnt6 == cnt9);
        }

        if(dp[idx][flag][cnt3][cnt6][cnt9] != -1){
            return dp[idx][flag][cnt3][cnt6][cnt9];
        }

        int limit = N[idx] - '0';

        if(flag == true){
            limit = 9;
        }

        int ans =0;

        for(int dig =0; dig<= limit; dig++){
            if(dig < N[idx] - '0'){
                if(dig == 3){
                    ans+= f_Dp(idx+1, true, N, cnt3+1, cnt6, cnt9);
                }
                else if(dig == 6){
                    ans+= f_Dp(idx+1, true, N, cnt3, cnt6+1, cnt9);
                }
                else if(dig == 9){
                    ans+= f_Dp(idx+1, true, N, cnt3, cnt6, cnt9+1);
                }
                else{

                    ans+= f_Dp(idx+1, true, N, cnt3, cnt6, cnt9);

                }
            }
            else{

                if(dig == 3){
                    ans+= f_Dp(idx+1, flag, N, cnt3+1, cnt6, cnt9);
                }
                else if(dig == 6){
                    ans+= f_Dp(idx+1, flag, N, cnt3, cnt6+1, cnt9);
                }
                else if(dig == 9){
                    ans+= f_Dp(idx+1, flag, N, cnt3, cnt6, cnt9+1);
                }
                else{

                    ans+= f_Dp(idx+1, flag, N, cnt3, cnt6, cnt9);

                }

            }
        }


        return dp[idx][flag][cnt3][cnt6][cnt9] = ans;



   

}


void solve (string l, string r){   // 0 1 

    //vector<vector<vector<int> > > dp(r.size()+1, vector<vector<int>> (2, vector<int> (r.size()+1, -1)));
    memset(dp, -1 , sizeof(dp));
    
   int R = f_Dp(0, false, r, 0 , 0 , 0);

   memset(dp, -1 , sizeof(dp));
     int L = f_Dp(0, false, l, 0 , 0 , 0);

    int for_L = brute(l);

   cout << R - L  + for_L << endl;


}
int main(){

    int test;

    cin >> test;

  

    while(test--){
         string l , r;
        cin >> l >> r;

        solve(l,r);
    }
    

}
