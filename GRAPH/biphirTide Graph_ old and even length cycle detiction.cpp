
#include<bits/stdc++.h>
using namespace std;


vector<int> adj[1000005];
int v, E;
bool checkBipartite_dfs(int node, int colour, vector<int> &col){   // o(n)
   
   col[node] = colour;

    for(auto it: adj[node]){
        if(col[it] == -1){
            if(checkBipartite_dfs(it, !colour, col)){
                return true;
            }
        }

        else if(col[it] == colour){
            return true;
        }

    }

    return false;
}

bool checkBipartite_bfs(int node, int colour, vector<int> &col){  // o(n)
    col[node] = colour;

    queue<pair<int, int>> q;
    q.push({node, colour});

    while(!q.empty()){
        int n = q.front().first;
        int colr = q.front().second;
        q.pop();

        for(auto it: adj[n]){
            if(col[it] == -1){
                q.push({it, !colr});
                col[it] = !colr;
            }
            else if(col[it] == colr){
                return true;
            }
        }
    }

    return false;
}

int main(){

   
    cin >> v >> E;
    vector<int> col(v + 1, -1);

    for(int i=0; i<E; i++){
        int u, v;
        cin >>  u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
   
    }

    if (checkBipartite_bfs(1, 1, col))
    {
        cout << "odd cycle" << endl;
    }
    else{
        cout << " even cycle " << endl;
    }

}