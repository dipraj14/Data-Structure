#include<bits/stdc++.h>
using namespace std;
//#define int long long int

class DSU{
    public:
        vector<int> parent, size;
    public:
        DSU(int n){
            for(int i=0; i<=n; i++){

                parent.push_back(i);
                size.push_back(1);

            }
        }
        int find_P(int node){
            if(node == parent[node]){
                return node;
            }
            return parent[node] = find_P(parent[node]);
        }
        void unino_S(int u, int v){
            int pu = u;
            int pv = v;

            if(pv == pu){
                return;
            }
            
            if(size[pu] < size[pv]){
                parent[pu] = pv;
                size[pv] += size[pu];
            }
            else{
                parent[pv] = pu;
                size[pu] += size[pv];
            }
        }
};
struct info{
    int u, v, wt;
    
    info(int _u, int _v, int _wt){
        u = _u;
        v = _v;
        wt = _wt;
    }
    
};
bool comp(info p1, info p2){

    if(p1.wt < p2.wt){
        return true;
    }
    return false;


}
void kruskal_algo(){
    int n,  m;
    cin >> n >> m;
    vector<info> edges;
    int ansW = 0;

    for(int i=0;i <m;i ++){
        int u, v , wt;
        cin >> u >> v >> wt;
        edges.push_back(info(u, v, wt));
    }

    // o(n log n) for sorting
    sort(edges.begin(), edges.end(), comp);

    // for(auto it : edges) cout << it.u<<" "<< it.v << " " << it.wt << " "<< endl; 

    DSU dsu(n);
    vector<pair<int,int>> mst;
    // for DSu o(4 alpha) for all the edges ---> M * 4 alpha ---> M is no of edges    
    for(auto &it: edges){
        int u = it.u;
        int v = it.v;
        int wt = it.wt;
        
        if(dsu.find_P(u) != dsu.find_P(v)){
            ansW += wt;
            mst.push_back({u, v}); 
            dsu.unino_S(u, v );
        }
    }

   cout <<  ansW << endl;

   for(auto it : mst) cout << it.first << " - " << it.second << endl; 

}

int main(){
     kruskal_algo();      // 0( n log n + M * 4 alpha)   -> overall ---> o(n log n)

}
