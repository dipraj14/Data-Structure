
/*
// for 1 based index graph
// for 0 baseed -- https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1#
#include <bits/stdc++.h>
using namespace std;

#define int long long int


vector<bool> vis;
int V,E;

bool cycle_check_DFS(int node, int pre, vector<int> adj[]){
    vis[node] = true;
    for(auto it: adj[node]){
        if(!vis[it]){
            if(cycle_check_DFS(it,node, adj) == true){
                return true;
            }
        }
        else if(it != pre){
            return true;  

        }
    }
    return false;
}
bool iscycle(vector<int> adj[]){
    vis.resize(V+1, 0);
    for(int i=1 ; i<=V ;i++){
        if(! vis[i]){
            if( cycle_check_DFS(i, -1, adj)){
                return true;
            }
           
        }
    }
     return false;
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

    cout<< iscycle(adj);



}  

*/


// Cycle detection for Directed Graph using DFS

#include <bits/stdc++.h>
using namespace std;

#define int long long int


vector<int> vis;

int V,E;

bool cycle_check_DFS(int node, vector<int> adj[]){
    vis[node] = 2;

    

    for(auto it: adj[node]){
        if(vis[it] == 0){
            if(cycle_check_DFS(it, adj) == true){
                return true;
            }
        }
        else if(vis[it] == 2){
            return true;  

        }
    }
    vis[node] = 1;
    return false;
}
bool iscycle(vector<int> adj[]){
    vis.resize(V+1, 0);
    for(int i=1 ; i<=V ;i++){
        if(! vis[i]){
            if( cycle_check_DFS(i, adj)){
                return true;
            }
           
        }
    }
     return false;
}
signed main() {

    cin >> V >> E;

    vector<int> adj[V+1];
   //parent.resize(V+1);
    

    for(int i=0 ;i< E; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
       // adj[v].push_back(u);
    }

   

    cout<< iscycle(adj);
    /*cout << endl;
     for(int it: parent){
        cout<< it <<" ";
    }
    */




}  