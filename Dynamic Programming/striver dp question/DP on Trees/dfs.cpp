#include<bits/stdc++.h>
using namespace std;

vector<int> adj[10005];
vector<int> p(10005);

void dfs(int node, int parent ){
    cout << node<< " " << parent <<" " ;
    //p.push_back(node);

    for(auto it: adj[node]){
        if(it != parent){
            dfs(it, node);

           // p.push_back(it);



        }
    }

    //cout << node <<" ";
}
int main(){
    int n;
    cin >> n;

    adj->resize(n+1);

    for(int i=1;i <n; i++){
        int u,v;
        cin >> u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);

    
    





}