#include<bits/stdc++.h>
using namespace std;

vector<int> adj[2 * 100005];
int level[2 * 100005];
int parent[2*100005][18];

map< pair<int,int> ,int> roadno;

int depth[2*100005];
vector<int> ans(2*100005);

void dfs(int node, int par = 0, int lev = 0){   // binary lifting

    parent[node][0] = par;
    level[node] = lev;

    for(int i=1; i<18; i++){
        parent[node][i] = parent[parent[node][i-1]][i-1];
    }

    for(auto it: adj[node]){
        if(it != par){
            dfs(it, node, lev + 1);
        }
    }

}

void dfsAdd(int node, int par =0){
    for(auto it: adj[node]){
        if(it != par){
            dfsAdd(it, node);
           // cout << node << " "<<it <<" " << depth[node] <<" " << depth[it] << endl;
            depth[node] += depth[it];
        }
    }

    if(par != 0){
        
        //cout << roadno[{node, par}]<<" -> "<< depth[node] <<endl;
        ans[roadno[{node, par}] ] = depth[node];
    }
}

int kth_Partent(int node, int k){
    int cnt = 0;
   //int p = node;
    while (k)
    {
        if(k & 1){
            node = parent[node][cnt];
        }

         cnt++;
        k = k >> 1 ;
    }

    return node;

   
    
}

int Lca(int u, int v){
    if(level[u] > level[v]){
        swap(u,v);
    }
    int dist = level[v] - level[u];

    v = kth_Partent(v, dist);
    if(u == v){
        return u;
    }
    for(int i=17; i>=0; i--){
        if(parent[u][i] != parent[v][i]){
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}



int main(){
    int n;
    cin >> n ;

    for(int i=0;i <n-1; i++){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
        roadno[{u,v}] = i;
        roadno[{v,u}] = i;
    }

    dfs(1);
    int q;
    cin >> q;
    while(q--){

        int x,y;
        cin >> x >> y;

        depth[x] += 1;
        depth[y] += 1;

        depth[Lca(x,y)] -= 2;


 
    }
    dfsAdd(1);

    for(int i=0; i<n-1; i++){
       cout << ans[i] << " ";
    }
    cout <<endl;
   // for(int i=1; i<=n; i++){
   //    cout << depth[i] << " ";
   // }
}
