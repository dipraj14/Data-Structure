

// Tree Dimeter --->> cses


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
int diameter[200001];
int downpath[200001];

vector<int> childs_DownPaths;
void downPaths(int node ,int par = 0){
    int bestChildpath = 0;
    int leaf = 1;
    for(auto it: tree[node]){

        if(it != par){
            leaf = 0;
            downPaths(it, node);

            bestChildpath = max (bestChildpath, downpath[it]);
            //cout<< it<< " " << bestChildpath <<" "<< endl;
        }

    }
    //cout << node << " ";
    
    if(leaf){
         downpath[node] = 0;
    }
    else {
        downpath[node] = 1 + bestChildpath ;
    }
}
 
void solve(int node, int par)
{
    int ans = 0;
    
    vector<int> childs_DownPaths;

    for(auto it: tree[node]){
        if(it != par){
             solve(it, node);

            // cout << it <<" "<< downpath[it] <<endl;

             childs_DownPaths.push_back(downpath[it]);

             ans = max(ans, diameter[it]);
             //cout<< ans <<" " << endl;
        }
    }

    int numofChild = childs_DownPaths.size();
   // cout << numofChild << endl;

    sort(childs_DownPaths.begin(), childs_DownPaths.end());

    if(numofChild == 0) diameter[node] = 0;
    else if(numofChild == 1) diameter[node] = 1 + childs_DownPaths[0];
    else diameter[node] = 2 + childs_DownPaths[numofChild - 1] + childs_DownPaths[numofChild - 2];

    diameter[node] = max(diameter[node], ans); 
   
 
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
        
        fr(2,n+1)
        {
            int u,v;
            cin >> u >> v;
          
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        downPaths(1);

       // for(i = 1;i <= n; i++){
       //     cout << downpath[i] <<" ";
       // }
        cout << endl;
        
        
        
        solve(1, 0);

        //for(i = 1;i <= n; i++){
       //     cout << diameter[i] <<" ";
       // }
       // cout << endl;

        cout << diameter[1];
   }
   return 0;
}


// If in future in cse you forget the logic pls at first dry [first dry run remove the comments of downpaths funcation then dry the solve funcation]
// if you forget all the contept then wath ---> kartik arora video


