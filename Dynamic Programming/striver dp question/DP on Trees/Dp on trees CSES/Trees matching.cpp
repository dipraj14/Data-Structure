/*
#include<bits/stdc++.h>

const double pi=acos(-1.0);
using namespace std;
#define   endl    '\n'
#define   sl(n)     scanf("%lld",&n)
#define   mp      make_pair
#define   pb      push_back
#define   ppb     pop_back
#define   fi      first
#define   se      second
#define   ll      long long
#define   ull     unsigned long long
#define   ld      long double
#define   pii     pair<int, int>
#define   f(i,a,b)  for(ll i = (ll)(a); i < (ll)(b); i++)
#define   rf(i,a,b)   for(ll i = (ll)(a); i > (ll)(b); i--)
#define   ms(a,b)   memset((a),(b),sizeof(a))
#define   abs(x)    ((x<0)?(-(x)):(x))
#define   MAX     200005
#define   inf     LLONG_MAX
#define   ninf    LLONG_MIN
#define   MIN     INT_MIN
#define   yeet    return 0;
#define tihs if(fopen("input.txt","r"))freopen("input.txt", "r", stdin),freopen("output.txt", "w", stdout);

#define fast_io ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

inline long long  MAX2(long long  a, long long  b){return (a)>(b)?(a):(b);}
inline long long  MAX3(long long  a, long long  b,long long  c){return (a)>(b)?((a)>(c)?(a):(c)):((b)>(c)?(b):(c));}
inline long long  MIN2(long long  a, long long  b){return (a)<(b)?(a):(b);}
inline long long  MIN3(long long  a, long long b,long long c){return (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c));}


int mod = 1e9 +7 ;



vector<int>adj[MAX];
ll dp[MAX][2];

void dfs (int src,int par){
            int leaf=1;
            dp[src][1]=0;
            dp[src][0]=0;

            for(auto child:adj[src]){
                    if(child!=par){
                        leaf=0;
                         dfs(child,src);
                    }
            }
        if(leaf==1)return ;

        for(auto child:adj[src]){
               if(child!=par){
               dp[src][0]+=MAX2(dp[child][0],dp[child][1]);

               }
        }

        for(auto child:adj[src]){
            if(child!=par) {
                 dp[src][1]=MAX2(dp[src][1],1+ dp[child][0]+( dp[src][0]-MAX2(dp[child][0],dp[child][1])));
        }
        }

      }

 int main(){
     tihs;
     int n;
     cin>>n;
     for(int i=0;i<n-1;i++){
        int ss,ee;
        cin>>ss>>ee;
        adj[ss].pb(ee);
        adj[ee].pb(ss);
     }
     dfs(1,0);
     cout<<MAX2(dp[1][0],dp[1][1])<<endl;
     }


*/

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
 
vector<int> tree[200001];
int dp[200001][2];

int level;
 
void solve(int src, int par, int lev = 0)
{
   level = lev;
    for(int child : tree[src])
    {
        if(child != par)
        {
            
            solve(child, src, lev+1);
        }
    }
 
}
 
int main() {
   fast_io;
   ll t,n,m,x,i,j,k,q;
   //cin >> t;
   t = 1;
   while(t--)
   {
        cin >> n;
        vector<int> ans(n+1);
        int flag = 1;
        int first;
        fr(2,n+1)
        {
            int u,v;
            cin >> u >> v;
            if(flag = 1){
                first = u;
                flag = 0;
            }
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
       
        solve(1, 0);
        cout << level ;
   }
   return 0;
}


