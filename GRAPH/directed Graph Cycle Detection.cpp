#include<bits/stdc++.h>
using namespace std;

int vis[1000005];
int pathVis[1000005];
vector<int> adj[1000005];
int v, E;
bool Dg_cycle_detec_Dfs(int node){

    vis[node] = 1;
    pathVis[node] = 1;

    for(auto it: adj[node]){
        if(!vis[it]){
            if(Dg_cycle_detec_Dfs(it)){
                return true;
            }
        }
        else if(vis[it] == 1 && pathVis[it] == 1){
            return true;
        } 
    }
    pathVis[node] = 0;
    return false;

}
int main(){

    cin >> v >> E;

    for(int i=0; i<E; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
       
    }

    bool flag = false;

    for(int i=1; i<=v; i++){   // we triverse multiple component of a graph 

        if(!vis[i]){
            if(Dg_cycle_detec_Dfs(i)){
                flag = true;
                break;
            }
        }

    }

    if(flag){
        cout<< "Cycvle Dtected" << endl;

    }
    else{
        cout << "there was not cycle " << endl; 
    }

}