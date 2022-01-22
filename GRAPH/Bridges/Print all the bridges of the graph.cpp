
#include<bits/stdc++.h>
using namespace std;

vector<bool> vis;
vector<int> tin(10005);
vector<int> low(10005);
vector<int> adj[10005];


void bridges_dfs(int node, int parent, int tm){   // this is Eiular tour for bridges
    
    vis[node] = 1;

    tin[node] = low[node] = tm++;

    for(auto it: adj[node]){
        if(it == parent) continue;

        if(vis[it] == 1){
            low[node] = min (low[it], low[node] );
        }
        else {
            bridges_dfs(it, node, tm);
            low[node] = min(low[node], low[it]);

            if(low[it] > tin[node]){

                cout << it <<" " << node << endl;
            }
        }
    }



}



int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	//adj->resize(V+1);

       // low.resize(V+1);

        //tin.resize(V+1);

        vis.resize(V+1, 0);
        

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}

        int tm = 0;

        for(int i=1; i<= V; i++){
            if(!vis[i]){
                bridges_dfs(i, 0, tm);
            }
        }
      
    
	}
	return 0;
}  

