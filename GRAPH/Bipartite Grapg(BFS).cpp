
// for those graph whose starting index is 0
#include <bits/stdc++.h>
using namespace std;



bool bfs_cycle_check(int start, int V, vector<int> adj[], vector<int> &colour) {

    queue<int> q;

    q.push(start);
    colour[start] = 1;

    while(!q.empty()){
        int node = q.front();

        q.pop();

        for(auto it : adj[node]){
            if(colour[it] == -1){
                colour[it] = 1- colour[node];
                q.push(it);
            }
            else if(colour[it] == colour[node]){
                return false;
            }
        }


    }

   

    return true;
       

        
        
}

bool isbipartite(int V, vector<int> adj[] ){

    vector<int> colour(V+1, -1);
    for(int i=1; i<=V ;i++){
        if(colour[i] == -1){
            if (! bfs_cycle_check(i, V, adj , colour)){
                return false;
            }
        }
    }
    return true;

}

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>E;

        vector<int> adj[V+1];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
       
        if (isbipartite(V, adj) == true){
            cout<<"TRUE" <<endl;
        } 
        else{
            cout<<"FALSE" << endl;
        }
       
    }
    return 0;
}  

