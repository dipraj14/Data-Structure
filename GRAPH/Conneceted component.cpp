

// for 1 based index graph
// connected component code


#include <bits/stdc++.h>
using namespace std;

#define int long long int


vector<bool> vis;
int V,E;

void dfs(int node, vector<int> adj[]){
    vis[node] = true;
    for(auto it: adj[node]){
        if(!vis[it]){
           dfs(it, adj);
        }
    }

}
int connected_compo(vector<int> adj[], int compo){
    vis.resize(V+1, 0);
    for(int i=1 ; i<=V ;i++){
        if(! vis[i]){
            dfs(i, adj);
            compo++;
           
        }
    }

    return compo;
 
}
signed main() {

    cin >> V >> E;

    vector<int> adj[V+1];
    

    for(int i=0 ;i< E; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int compo = 0;

    cout<< connected_compo(adj, compo);



}  