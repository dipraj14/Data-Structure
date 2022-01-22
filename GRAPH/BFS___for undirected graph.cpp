#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

 // all the component bfs
 
vector<bool> visited(100005);

void bfsOfGraph(int V, vector<int> adj[], int start) {

       
        
        vector<int> result;
         queue<int> q;
        
           

                q.push(start);
                visited[start] = true;

                while (!q.empty())
                {
                    int node = q.front();
                    q.pop();
                    result.push_back(node);

                    for (auto it: adj[node])
                    {
                        if (!visited[it])
                        {
                            q.push(it);
                            visited[it] = true;
                            
                        }
                    }
                }
        
            

       

        for(auto it: result) {
            cout << it << " ";
        }
        cout << endl;
        // Code here
}

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>E;

        vector<int> adj[V];   // if 1 is the starting node thenn v+1 is the size/....

         visited.resize(adj->size()+1, false);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);   //  if this is the undirected graph then there shode be one direction
        }
    vector<int> ans;

      for(int i=0; i<V; i++){
          if(!visited[i]){
                bfsOfGraph(V, adj , i); // starting  node
          }

      }
        //vector<int> ans = bfsOfGraph(V, adj , 0); // starting  node
       
    }
    return 0;
}  // } Driver Code Ends