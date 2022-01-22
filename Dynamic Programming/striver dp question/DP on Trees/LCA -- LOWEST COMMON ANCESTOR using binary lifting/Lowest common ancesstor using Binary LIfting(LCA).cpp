
// constrain ---> n <= 10^5
//    Q <= 10^5

/*
         1                         quries:       output:
         |                            1 
         2                           7  10          4       
         |
         3
         |
         4
        / \

       5   6
      /     \
     7       8
              \
               9
                \
                10
 

*/


#include<bits/stdc++.h>
using namespace std;

vector<int> adj[10005];

int parent[100005][17];       // log(100005) near equl to 16 // so we take 17 size
int level[100005];

void dfs(int node, int par, int lev = 0 ){          // Binary Lifting   // complixity- > o(n * 16)  // or o(n * log(n)(base 2))
    //cout << node<< " " <<parent;
    //cout<<endl;
    
    parent[node][0] = par;

    level[node] = lev;

    for(int i=1;i <16;i ++){
        parent[node][i] = parent[parent[node][i-1]][i-1];
    }
    
    for(auto it: adj[node]){
        if(it != par){
            dfs(it, node, lev+ 1);
           
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

int LCA(int u, int v){

    if(level[u] > level[v]){
        swap(u,v);
    }

    int k = level[v] - level[u];
    v = find_Kth_Parent(v, k);

    if(u == v){
        return u;
    }

    for(int i=16; i>=0; i--){
        if(parent[u][i] != parent[v][i]){
            u = parent[u][i];
            v = parent[v][i];
        } 
    }

    return parent[u][0];

}
int main(){
    int n;
    cin >> n;

    adj->resize(n+1);

    for(int i=1;i <n; i++){
        int u,v;
        cin >> u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

   // for(int i=1; i<11; i++){
   //     cout << nnnnnnn[i] <<" ";
   // }

    int query ;
    cin >> query;
    while(query --){    // this may givis TLE Because for dfs--> o(n * 16) and  and for q quries o(Q * log k) --overall --> o(n* 16) + o(Q * log k)...
        int n1, n2;
        cin >> n1 >> n2;

        cout << LCA(n1, n2);      // overall --> o(Q* log k) + log(N)(base 2)  or o(Q * log k(base 2)) + o(16)
    }


}


/*
// company querys 2 ---> CSES using LCA //....

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
int level[200001];
void binary_lifting(int src, int par, int lev =0)
{
    up[src][0] = par;

    level[src] = lev;


    for(int i = 1; i < 20; i++)
    {
        if(up[src][i-1] != -1)
            up[src][i] = up[up[src][i-1]][i-1];
        else up[src][i] = -1;
    }
 
    for(int child : tree[src])
    {
        if(child != par)
            binary_lifting(child, src, lev+1);
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

int LCA(int u, int v){

    if(level[u] > level[v]){
        swap(u,v);
    }

    int k = level[v] - level[u];
    v = ans_query(v, k);

    if(u == v){
        return u;
    }

    for(int i=19; i>=0; i--){
        if(up[u][i] != up[v][i]){
            u = up[u][i];
            v = up[v][i];
        }
    }

    return up[u][0];

}
 
int main() {
   fast_io;
   ll t,n,m,x,i,j,k,q;
  
  
  
        cin >> n >> q;
 
    for(int i=2;i <=n; i++){
     
        cin >> x;

        tree[x].push_back(i);
        tree[i].push_back(x);
    } 
        binary_lifting(1, -1);
        while(q--){
            int n1, n2;
            cin >> n1 >> n2;
            int lca =  LCA(n1, n2) ;
            
            cout << lca << endl;
      
   }
   return 0;
}
*/