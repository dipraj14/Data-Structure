
// for those graph whose starting index is 0

#include <bits/stdc++.h>
using namespace std;


bool bfs_cycle_check(int start, int V, vector<int> adj[], vector<bool> &vis) {

    queue<pair<int,int>> q;

    q.push({start,-1});
    vis[start] = true;

    while(!q.empty()){
        int node = q.front().first;
        int pre = q.front().second;

        q.pop();

        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it] = true;
                q.push({it, node});
            }
            else if(pre != it){
                return true;
            }
        }


    }

    return false;
       

        
        
}

bool isCycle(int V, vector<int> adj[] ){

    vector<bool> vis(V+1, 0);
    for(int i=1; i<=V ;i++){
        if(!vis[i]){
            if (bfs_cycle_check(i, V, adj , vis)){
                return true;
            }
        }
    }
    return false;

}

// { Driver Code Starts.
int main() {
    int tc = 1;
   // cin >> tc;
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
       
        if (isCycle(V, adj) == true){
            cout<<"TRUE" <<endl;
        } 
        else{
            cout<<"FALSE" << endl;
        }
       
    }
    return 0;
}  

// // for those graph whose starting index is 1

/*

#include <bits/stdc++.h>
using namespace std;


bool bfs_cycle_check(int start, int V, vector<int> adj[], vector<bool> &vis) {

    queue<pair<int,int>> q;

    q.push({start,-1});
    vis[start] = true;

    while(!q.empty()){
        int node = q.front().first;
        int prev = q.front().second;

        q.pop();

        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it] = true;
                q.push({it, node});
            }
            else if(prev != it){
                return true;
            }
        }


    }

    return false;
       

        
        
}

bool isCycle(int V, vector<int> adj[] ){

    vector<bool> vis(V+1, 0);  // 
    for(int i=1; i<=V ;i++){  // 1 2 3 4 5 6
        if(!vis[i]){
            if (bfs_cycle_check(i, V, adj , vis)){
                return true;
            }
        }
    }
    return false;

}


int main() {
    int tc =1 ;
    //cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>E;  //  6 6

        vector<int> adj[V+1];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
       
        if (isCycle(V, adj) == true){
            cout<<"TRUE" <<endl;
        } 
        else{
            cout<<"FALSE" << endl;
        }
       
    }
    return 0;
}  

*/