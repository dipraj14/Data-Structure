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
        /*
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
        */
};
struct info{
    int l, r, c;
    info(int _l, int _r, int _c){
         l= _l;
        r = _r;
        c = _c;
    }
};
void colourfullarrya(){
    int n, q;
    cin >> n>> q;

    vector<info> offline_quries;

    while(q --){
        int l , r, c;
        cin >> l >> r >> c;
        offline_quries.push_back(info(l,r,c));
        
    }

    reverse(offline_quries.begin(), offline_quries.end());
    vector<int> colur(n+1);
    DSU dsu(n+1);

    for(auto &it: offline_quries){
        int l = it.l;
        int r = it.r;
        int col = it.c;

        for(int i = dsu.find_P(l); i<=r; i = dsu.find_P(i)){

            colur[i] = col;
            dsu.parent[i] = i+1;
        }

    }

    for(int i=1; i<=n; i++){
        cout << colur[i] << " ";
    }
}

int main(){
    colourfullarrya();
}