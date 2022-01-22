#include<bits/stdc++.h>
using namespace std;

vector<int> adj[10005];
void Bfs(int root){
    queue<pair<int,int>> q;

    q.push({root, -1});
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;

        q.pop();

        cout << node << " ";

        for(auto it: adj[node]){
            if(it != parent){
                q.push({it, node});
            }
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

    Bfs(1);


}





