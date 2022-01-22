/*
// Cpp program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to form edge between
// two vertices src and dest
void add_edge(vector<int> adj[],
			int src, int dest)
{
	adj[src].push_back(dest);
	adj[dest].push_back(src);
}

// Function which finds all the paths
// and stores it in paths array
void find_paths(vector<vector<int> >& paths,
				vector<int>& path,
				vector<int> parent[],
				int n, int u)
{
	// Base Case
	if (u == -1) {
		paths.push_back(path);
		return;
	}

	// Loop for all the parents
	// of the given vertex
	for (int par : parent[u]) {

		// Insert the current
		// vertex in path
		path.push_back(u);

		// Recursive call for its parent
		find_paths(paths, path, parent,
				n, par);

		// Remove the current vertex
		path.pop_back();
	}
}

// Function which performs bfs
// from the given source vertex
void bfs(vector<int> adj[], vector<int> parent[], int n, int start)
{

	vector<int> dist(n, INT_MAX);

	queue<int> q;


	q.push(start);
	parent[start] = { -1 };

	dist[start] = 0;

	
	while (!q.empty()) {
		int node = q.front();

		q.pop();

		for (int v : adj[node]) {

			if (dist[v] > dist[node] + 1) {

			
				dist[v] = dist[node] + 1;
				q.push(v);
				parent[v].clear();
				parent[v].push_back(node);
			}
			else if (dist[v] == dist[node] + 1) {

				
				parent[v].push_back(node);
			}
		}
	}
}


void print_paths(vector<int> adj[], int n, int start, int end)
{
	vector<vector<int> > paths;
	vector<int> path;
	vector<int> parent[n];


	bfs(adj, parent, n, start);


	find_paths(paths, path, parent, n, end);

	for (auto v : paths) {

		
		reverse(v.begin(), v.end());

	
		for (int u : v)
			cout << u << " ";
		cout << endl;
	}
}

// Driver Code
int main()
{
	
	int n = 6;

	
	vector<int> adj[n];

	// Given Graph
	add_edge(adj, 0, 1);
	add_edge(adj, 0, 2);
	add_edge(adj, 1, 3);
	add_edge(adj, 1, 4);
	add_edge(adj, 2, 3);
	add_edge(adj, 3, 5);
	add_edge(adj, 4, 5);

	// Given source and destination
	int src = 0;
	int dest = n - 1;

	// Function Call
	print_paths(adj, n, src, dest);

	return 0;
}
*/




#include <bits/stdc++.h>
using namespace std;


   
void bfsOfGraph(int V, vector<int> adj[], int start) {

        vector<bool> visited(adj->size(), false);
		int dist[V];

		for(int i=0;i<V;i++){
			dist[i] = INT_MAX;
		}
        
        
         queue<int> q;
		    
				dist[start] = 0;
                q.push(start);
                

                while (!q.empty())
                {
                    int node = q.front();
                    q.pop();
                   

                    for (auto it: adj[node])
                    {
                        if (dist[node] + 1 < dist[it])
                        {
							dist[it] = dist[node] + 1 ; 
                            q.push(it);
                          
                            
                        }
                    }
                }
        
            
          for (int i = 0; i < V; i++) {
            cout << dist[i] << " ";
          }
          cout << endl;
       

        
        
}

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            //adj[v].push_back(u);
        }
       
        bfsOfGraph(V, adj , 0); // starting  node
       
    }
    return 0;
}  // } Driver Code Ends