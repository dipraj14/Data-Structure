// Ques : Check any two component of the graph Connected or not

// Dsu byt size......

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


signed main(){

    DSU dsu(10000);
    int m;
    cin >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        dsu.unino_S(u,v);
    }

    if(dsu.find_P(3) != dsu.find_P(2)){

        cout << "Different Component" << endl;

    }
    else{
        cout << "Same" << endl;
    }

    

    

    
}
















/*
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >>n;


    string s;

    cin >> s;
    
    //set<int> st;
    int count=0;
    //st.insert(count);

    int ans = 0;
    
    for(int i=0;i<n;i ++){
 
       if(s[i] == 'A'){
           count = count+1;
           //st.insert(count);
           if(count < 0){
               ans++;
           }
       }
       else if(s[i] == 'B'){
           count = count - 1;
           //st.insert(count);
           if(count < 0){
               ans++;
           }
       }

       

       
    }

    cout << ans ;
}

*/