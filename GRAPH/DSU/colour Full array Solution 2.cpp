/*
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
       
        void union_s(int u, int v){
          parent[v] = u;
        }
      
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
//     vector<int> colur(n+1, -1);
    vector<int> colur(n+1);
    DSU dsu(n+1);

    for(auto &it: offline_quries){
        int l = it.l; // 2 // 1
        int r = it.r; // 6  // 3
        int col = it.c;

        int avibSlot = dsu.find_P(r);
        while(avibSlot > 0 && avibSlot >= l){
//             if(colur[avibSlot] == -1){   // no need to assign -1 all the idx 
//                 colur[avibSlot] = col;
//             }
                colur[avibSlot] = col;
               //cout << dsu.find_P(avibSlot - 1) <<" " <<avibSlot<<endl;
           dsu.union_s(dsu.find_P(avibSlot - 1), avibSlot);
          // dsu.parent[avibSlot] = dsu.find_P(avibSlot - 1 );
            avibSlot = dsu.find_P(avibSlot);
            
        }

    }

    for(int i=1; i<=n; i++){
        cout << colur[i] << endl;
    }
}

int main(){
    colourfullarrya();
}
*/

// accepted solution -->
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
          void union_s(int u, int v){
          parent[v] = u;
        }
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

        for(int i = dsu.find_P(r); i>=l; i = dsu.find_P(i)){
           // cout << i<<" -> val" << " ";
            colur[i] = col;
            
            dsu.union_s(dsu.find_P(i - 1), i);
        }

    }

    for(int i=1; i<=n; i++){
        cout << colur[i] << " ";
    }
}

int main(){
    colourfullarrya();
}
