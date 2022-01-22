#include <bits/stdc++.h>

using namespace std;
 

 
#define endl "\n"
#define ima INT_MAX
#define imi INT_MIN
#define lma LLONG_MAX
#define lmi LLONG_MIN


#define rep(i,a,b) for (lli i=a;i<b;i++)
#define rep_rev(i,a,b) for (lli i=b-1;i>=a;i--)
#define iter(it,a) for(auto it=a.begin();it!=a.end();it++)
#define for_e(x,v) for(auto &x : v)
#define mem0(X) memset((X), 0, sizeof((X)))
#define mem1(X) memset((X), -1, sizeof((X)))

#define read(a) rep(i, 0, sz(a)) cin >> a[i]
#define print(a) rep(i, 0, sz(a)) cout << a[i]<<" "


#define mp make_pair
#define f first
#define s second
#define sz(x) ((lli)x.size()) // containers
#define pb push_back
#define eb emplace_back
#define em emplace
#define all(v)  v.begin(),v.end()


#define lli long long int
#define pii pair<int,int>
#define vii vector<pii>
#define vi vector<int>
#define vl vector<lli>
#define vll vector<pair<lli,lli>>
#define pll pair<lli,lli>
#define vvi vector<vector<int>>
#define vvl vector<vector<lli>>


#define INF 2E9
#define PI 3.14159265358979323846
#define mod 1000000007
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl


#define i1(a) lli a; cin>>a;
#define il(a) lli a;cin>>a;
#define i2(a,b) lli a,b; cin>>a>>b;
#define i3(a,b,c) lli a,b,c; cin>>a>>b>>c;
#define i4(a,b,c,d) lli a,b,c,d; cin>>a>>b>>c>>d;

#define test(t) lli t; cin>>t; while(t--)

 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();


lli power_mod(lli a,lli x){if(x==0) return 1;lli y=power_mod(a,x/2);lli ans=(y*y)%mod; if(x%2) ans=(ans*a)%mod;return ans;}
lli inv(lli a){return power_mod(a,mod-2);}
lli power(lli a, lli x){ if(x==0) return 1; lli y= power(a,x/2); lli ans=(y*y); if(x%2) ans*=a; return ans; }
lli gcd(lli a,lli b){if(a==0||b==0) return a+b;  else return gcd(b%a,a); }


void starter(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}



lli fab(lli n, vl &dp){

	

		if(n <= 1 ){
			return n;
		}
		else{
   
   		lli left = fab(n-1, dp);
   		lli right = fab(n-2 ,dp);

   		return left+ right;
		}	 
  


}

void solve() {


lli n;
cin >> n;
vl dp(100,-1);
cout<< fab (n, dp);


}


signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    //starter();

 
    test(t){

     solve();
 	}

 	return 0;
   

}