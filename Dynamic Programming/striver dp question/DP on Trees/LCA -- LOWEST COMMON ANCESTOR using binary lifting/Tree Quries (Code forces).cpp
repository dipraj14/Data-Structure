#include<bits/stdc++.h>
using namespace std;

vector<int> adj[2 * 100005];
int level[2 * 100005];
int parent[2*100005][18];

void dfs(int node, int par = 0, int lev = 0){   // binary lifting

    parent[node][0] = par;
    level[node] = lev;

    for(int i=1; i<18; i++){
        parent[node][i] = parent[parent[node][i-1]][i-1];
    }

    for(auto it: adj[node]){
        if(it != par){
            dfs(it, node, lev + 1);
        }
    }

}

int kth_Partent(int node, int k){
    int cnt = 0;
   //int p = node;
    while (k)
    {
        if(k & 1){
            node = parent[node][cnt];
        }

         cnt++;
        k = k >> 1 ;
    }

    return node;

   
    
}

int Lca(int u, int v){
    if(level[u] > level[v]){
        swap(u,v);
    }
    int dist = level[v] - level[u];

    v = kth_Partent(v, dist);
    if(u == v){
        return u;
    }
    for(int i=17; i>=0; i--){
        if(parent[u][i] != parent[v][i]){
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}



int main(){
    int n, q;
    cin >> n >> q;

    for(int i=0;i <n-1; i++){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);
    
    while(q--){
        int num;
        cin >> num;

        vector<int> quries(num);
        int deepest = 0;

        for(int i=0; i<num; i++){
            cin >> quries[i];

            if(level[quries[i]] > level[deepest]){
                deepest = quries[i];
            }

        }

        bool flag = true;

        for(auto it: quries){
            int lca = Lca(it, deepest);
          
             if((level[it] - level[lca]) > 1){
                flag = false;
                break;
            }
        }

        if(flag == true){
            cout<< "YES" << endl;
        }
        else{
            cout << "No" << endl;
        }
        
    }
}
