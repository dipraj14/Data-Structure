
// you will given x node; your task to print the path from root to that node 
/*
            1                       input:    output:
          /  \  \                       9       1 4 8 9
         2   3   4                            
           / \ \   \                           
          5  6  7   8                   
                     \
                      9
                       \
                       10 
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> adj[10005];
bool dfs(int node, int parent, vector<int> &path, int x ){


    path.push_back(node);

    if(node == x){
        return true;
    }
    
   
   

    for(auto it: adj[node]){
        if(it != parent){
            if(dfs(it, node, path, x) == true) return true;
        }
    }
    path.pop_back();
    return false;
}
int main(){
    int n;
    cin >> n;

   // adj->resize(n+1);

    for(int i=1;i <n; i++){
        int u,v;
        cin >> u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int x;
    cin >> x;

    vector<int> path;

    bool get_path  = dfs(1, -1, path, x);

    if(get_path == true){
        for(auto it: path){
            cout << it <<" ";
        }
        /*while(!path.empty()){
            cout<< path.top() << " ";
            path.pop();
        }
        */
    }
    else{

        return 0;
        
    }

    


}