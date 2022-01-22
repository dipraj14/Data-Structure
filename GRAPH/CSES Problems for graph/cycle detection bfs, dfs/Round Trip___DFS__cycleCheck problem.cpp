#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int
 
int V, E;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> parent;
int sp;
int ep;
 
bool dfs(int u, int p)
{

	vis[u] = true;
    parent[u] = p;
	for(auto it: adj[u])
	{
        if(it == p){
            continue;
        }
		if(vis[it])
		{
            sp = it;
            ep = u;
            return true;
			
		}
        if(!vis[it]){
            if(dfs(it,u)){
                return true;
            }

        }

	}
    return false;
}
 
bool visit_all(){
    for(int i=1; i<=V;i++){
        if(!vis[i]){
            if(dfs(i,-1)){
                return true;
            }
        }
    }
    return false;
}
 
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> V >> E ;

	adj.resize(V+1);

	vis.resize(V+1);
    parent.resize(V+1);

	for(auto i = 0; i < E; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

    if(!visit_all()){
        cout<< "IMPOSSIBLE"<<endl;
        return 0;
        
    }
    

        vector<int> ans;
        int tv = ep;
        ans.push_back(ep);

        while(tv != sp){
            ans.push_back(parent[tv]);
            tv = parent[tv];
        }
        ans.push_back(ep);

        cout<< ans.size() <<endl;
        for(auto it : ans){
            cout<< it <<" ";
        }
 
	
}
