
#include<bits/stdc++.h>
using namespace std;


void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storeDfs) {
        storeDfs.push_back(node); 
        vis[node] = 1; 
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(it, vis, adj, storeDfs); 

			//	cout << it <<" ";  // [ this is for when call are come back]
            }
        }
}

vector<int>dfsOfGraph(int V, vector<int> adj[]){
	    vector<int> storeDfs; 
	    vector<int> vis(V+1, 0); 
      for(int i = 1; i<=V ;i++) {
        if(!vis[i]) {
            dfs(i, vis, adj, storeDfs); 
        }
      }
	    return storeDfs; 
}



int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V+1];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
      
       cout<<endl;
        vector<int>ans =  dfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
		}
        cout<<endl;
	}
	return 0;
}  

