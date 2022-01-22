
// for those graph whose starting index is 0
#include <bits/stdc++.h>
using namespace std;
 vector<int> adj[10005];

bool dfs(int node,int col, vector<int> &colour) {
             colour[node] = col;

             for(auto it: adj[node]){
                 if(colour[it] == -1){
                     if(dfs(it, !col, colour) == false){
                         return false;
                     }
                 }
                 else if(colour[it] == colour[node]){
                     return false;
                 }
             }


             return true;
}




bool isbipartite(int V ){

    vector<int> colour(V+1, -1);

    for(int i=1; i<=V ;i++){
        if(colour[i] == -1){

            if ( dfs(i,0, colour) == false){
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

       adj->resize(V+1);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
       
        if (isbipartite(V) == true){
            cout<<"TRUE" <<endl;
        } 
        else{
            cout<<"FALSE" << endl;
        }
       
    }
    return 0;
}  

