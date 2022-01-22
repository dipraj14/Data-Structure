#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[], int start) {

        vector<bool> visited(adj->size(), false);
        
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
        
            

       

        return result;
        // Code here
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>E;

        vector<int> adj[V];   // if 1 is the starting node thenn v+1 is the size/....

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            //adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj , 0); // starting  node
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends