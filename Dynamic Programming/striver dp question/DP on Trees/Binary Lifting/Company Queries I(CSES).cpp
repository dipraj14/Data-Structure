
// Company Queries I ---> CSES problem // https://cses.fi/problemset/submit/1687/

#include<bits/stdc++.h>
using namespace std;

vector<int> adj[200001];

int parent[200001][20];       // log(100005) near equl to 16 // so we take 17 size


void dfs(int node, int par ){          // Binary Lifting   // complixity- > o(n * 16)  // or o(n * log(n)(base 2))
    //cout << node<< " " <<parent;
    //cout<<endl;
    
    parent[node][0] = par;

   

    for(int i=1;i <19;i ++){
        parent[node][i] = parent[parent[node][i-1]][i-1];
    }
    
    for(auto it: adj[node]){
        if(it != par){
            dfs(it, node);
           
        }
    }
}

int find_Kth_Parent(int node, int k){    // find kth parent using binary lifting  // tc - > o(log k(base 2))

    int p = node;
        int count = 0;
        while(k){
            if(k & 1){
                p = parent[p][count]; 
            }

            k = k >> 1;           // log k                                // overall --> o(n *16) + o(log k(base 2))
            count++;
            

        }

        return p;

}



int main(){
    int n, query;
    cin >> n >> query;

  
    
    //adj[1].push_back(1);

    for(int i=2;i <n+1; i++){
        int u;
        cin >> u;

        adj[u].push_back(i);
        adj[i].push_back(u);
    }

    dfs(1, -1);

   // for(int i=1; i<11; i++){
   //     cout << nnnnnnn[i] <<" ";
   // }


    while(query --){
        int n1, k;
        cin >>n1 >> k ;
        cout << find_Kth_Parent(n1, k) << endl;
    }


}







/*
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
int up[200001][20];
 
void binary_lifting(int src, int par)
{
    up[src][0] = par;
    for(int i = 1; i < 20; i++)
    {
        if(up[src][i-1] != -1)
            up[src][i] = up[up[src][i-1]][i-1];
        else up[src][i] = -1;
    }
 
    for(int child : tree[src])
    {
        if(child != par)
            binary_lifting(child, src);
    }
}
 
int ans_query(int node, int jump_required)
{
    if(node == -1 || jump_required == 0)
        return node;
 
    for(int i = 19; i >= 0; i--){
        if(jump_required >= (1<<i)){
            return ans_query(up[node][i], jump_required - (1<<i));
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
        cin >> n >> q;
        fr(2,n+1)
        {
            cin >> x;
            tree[x].push_back(i);
            tree[i].push_back(x);
        }
        binary_lifting(1, -1);
        while(q--){
            int node, k;
            cin >> node >> k;
            cout << ans_query(node, k) << '\n';
        }
   }
   return 0;
}

*/