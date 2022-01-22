
#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
vector<int> adj[200001];
vector<int> in(200001);
vector<int> out(200001);

int ans[200001];

void dfsIn(int node, int parent = 0){
    //cout << node ;
    in[node] = 0;

    for(auto it: adj[node]){

        if(it  == parent){continue;}

            dfsIn(it, node);
            in[node] = max(in[node], 1 + in[it] );
        

    }
}

void dfsOut(int node, int parent1 = -1, int parent2 = -1){
    //cout << node ;
    out[node] = 0;

    int deepestExceptNode = 0; 
    if(parent1 != -1){

        for(auto child: adj[parent1]){
        if(child == node  || child == parent2) {
            continue;
        }

        deepestExceptNode = max(deepestExceptNode, 1 + in[child]);
       // cout << deepestExceptNode <<" ";

    }

    }
    
    if(parent1 != -1){
        out[node] = 1 + max(out[parent1], deepestExceptNode);
    }
    

    for(auto child : adj[node]) {
        if(child == parent1){
            continue; 
        }
        dfsOut(child, node, parent1);
    }

   
  
}

/*
void dfs_ans(int node, int par){
    int mx1 =-1, mx2 =-1;

    ans[node] = out[node];
    for(auto it: adj[node]){
        if(it != par){
            dfs_ans(it, node);

            if(in[it] > mx1){
                mx1 = in[it];
            }
        }
    }
    ans[node] = max(ans[node], 1+ mx1);
}
*/

void solve(){

        int n;

        cin >> n;
        
       
        for(int i=0; i<n-1; i++)
        {
            int u,v;
            cin >> u >> v;
          
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
          
        dfsIn(1, 0);
        dfsOut(1, -1);

        //dfs_ans(1, 0);

          
       for(int i=1; i<=n; i++){
           ans[i] = max( out[i], in[i]);
       } 
       for(int i=1; i<=n; i++){
           cout << ans[i] <<" ";
       } 
         


}

signed main() {
   fast_io;

  solve();
 
  
   //return 0;
}




