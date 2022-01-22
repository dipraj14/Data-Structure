#include<bits/stdc++.h>
using namespace std;

vector<int> adj[10005];
int height = 0;
int level;
void dfs(int node, int parent, int lev){
    //cout << node<< " " ;

    height = max(height, lev + 1);

    level = lev;

    for(auto it: adj[node]){
        if(it != parent){
            dfs(it, node, lev + 1);
        }
    }

    
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
   
    dfs(1, -1, 0 );

    cout<< level << " " << height <<endl;


}