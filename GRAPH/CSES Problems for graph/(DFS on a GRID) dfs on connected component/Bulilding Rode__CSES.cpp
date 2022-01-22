



// for 1 based index graph


/*
#include <bits/stdc++.h>
using namespace std;

#define int long long int


vector<bool> vis;
int V,E;
vector<int> lead;

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
            lead.push_back(i);
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

    int cc = connected_compo(adj, compo);
    cout << cc-1<< endl;

    if(cc > 1){
        int u1 = lead[0];
        int v1;
        for(int i=1 ;i < cc;i++){

            v1 = lead[i];
            cout << u1 << " "<< v1 <<endl;
            u1 = v1;

        }
    }



}  
*/


#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int
 
int V, E;
int cc = 0;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> lead;
 
void dfs(int u)
{
	vis[u] = true;
	for(auto v: adj[u])
	{
		if(!vis[v])
		{
			dfs(v);
		}
	}
}
 
void process_cc()
{
	for(auto i = 1; i <= V; ++i)
	{
		if(!vis[i])
		{
			cc++;
			lead.push_back(i);
			dfs(i);
		}
	}
}
 
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> V >> E ;

	adj.resize(V+1);

	vis.resize(V+1);

	for(auto i = 0; i < E; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
 
	process_cc();
 
	cout << cc-1 << endl;
	if(cc > 1 )
	{
		int u = lead[0]; 
        int v;
		for(auto i = 1; i < cc; i++)
		{
			v = lead[i];
			cout << u << " " << v << endl;
			u = v;
		}
	}
}
