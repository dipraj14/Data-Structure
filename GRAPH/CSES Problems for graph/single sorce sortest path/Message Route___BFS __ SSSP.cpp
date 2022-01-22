#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int
 
int V, E;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> parent;
 
void BFS()
{

	queue<int> q;
    vis[1] = true;
    q.push(1);
    parent[1] = -1;
    while(!q.empty()){
        int n = q.front();
        q.pop();

        for(auto it : adj[n]){
            if(!vis[it]){
                q.push(it);
                vis[it] = true;
                parent[it] = n;
            }
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
    parent.resize(V+1);

    for(int i=0 ;i<=V;i++){
        parent[i] = -1;
    }

	for(auto i = 0; i < E; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
   
     BFS();

     if(parent[V] == -1){

         cout<< "IMPOSSIBLE" <<endl;
         return 0;

     }

    stack<int> st;
    int curr_node = V;
    while(curr_node != -1){

        st.push(curr_node);
        curr_node = parent[curr_node];

    }

    cout<< st.size() <<endl;

    while(!st.empty()){
        cout<< st.top() << " ";
        st.pop();
    }
 
	
}
