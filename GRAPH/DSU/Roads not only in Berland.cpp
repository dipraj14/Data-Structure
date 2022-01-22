// Ques : Check any two component of the graph Connected or not

// Dsu byt size......

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

    
    int m;
    cin >> m;
    int ansW = 0;
    DSU dsu(m);
    vector<pair<int,int>> oldroads;

    for(int i=1;i<m;i++){
        int u, v;
        cin >> u >> v;

        if(dsu.find_P(u) == dsu.find_P(v)){
            oldroads.push_back({u,v});
        }
        else{

            dsu.unino_rank(u,v);

        }
    }

    set<int> st;
    
    for(int i=1;i <=m; i++){
        st.insert(dsu.find_P(i));
    }
   // for(auto it: st){
    //    cout<< it<<" ";
   // }
   // cout<< endl;
    int newRoads = st.size() - 1;

    cout<< newRoads <<endl;

    vector<int> connectroads(st.begin(), st.end());
    int j =0;
    for(int i= 1;i<=newRoads; i++){
        cout<< oldroads[j].first <<" " << oldroads[j].second <<" "<< connectroads[i] << " "<< connectroads[i-1] << endl;
        j++;
    }
   

    

    

    
}
















