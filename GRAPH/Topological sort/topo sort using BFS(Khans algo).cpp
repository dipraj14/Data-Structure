
#include<bits/stdc++.h>
using namespace std;

vector<int>adj[100005];

vector<bool> vis(100005);
vector<int>indegree(100005);

// topologigal sort possible only Directed graph

void Khans_Algo_topoSort_BFS (int n ) {
    // trivers through all the edges of the graph
     for(int i=1; i<=n ; i++){
         //i -> it
         for(auto it: adj[i]){
             indegree[it] ++;
         }
     }
     queue<int> q;

     for(int i=1; i<=n; i++){
         if(indegree[i] == 0){
             q.push(i);
         }
     }

     vector<int> topoSort;

     while(!q.empty()){
         int node = q.front();
         q.pop();

         topoSort.push_back(node);
        // remove all the edges that originate fromm this 0 indegree
        // node -> it
         for(auto it: adj[node]){
             indegree[it]--;
             if(indegree[it] == 0){
                 q.push(it);
             }
         }

     }


     for(auto it: topoSort){
         cout << it <<" ";
     }

   
}




int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	adj->resize(V+1);
   

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		//adj[v].push_back(u);
    	}
      
      
      Khans_Algo_topoSort_BFS (V);

      
	}
	return 0;
}  

