

// Dsu Union by rank.....

#include<bits/stdc++.h>
using namespace std;
//#define int long long int

class DSU{
    public:
        vector<int> parent, size, rank;
    public:
        DSU(int n){
            for(int i=0; i<=n; i++){

                parent.push_back(i);
                size.push_back(1);
                rank.push_back(0);

            }
        }
        int find_P(int node){
            if(node == parent[node]){
                return node;
            }
            return parent[node] = find_P(parent[node]);
        }
        void unino_rank(int u, int v){
            int pu = u;
            int pv = v;

            if(pu == pv){
                return;
            }
            if(rank[pv] == rank[pu]){
                parent[pv] = pu;
                rank[pv]++;
            }
            
            else if(rank[pu] < rank[pv]){
                parent[pu] = pv;
               
            }
            else{
                parent[pv] = pu;
               
            }
        }
};


signed main(){

    DSU dsu(10000);
    int m;
    cin >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        dsu.unino_rank(u,v);
    }

    if(dsu.find_P(3) != dsu.find_P(2)){

        cout << "Different Component" << endl;

    }
    else{
        cout << "Same" << endl;
    }

    

    

    
}

