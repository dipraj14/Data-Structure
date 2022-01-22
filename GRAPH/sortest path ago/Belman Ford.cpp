#include<bits/stdc++.h>
using namespace std;
//#define int long long int


void belman_Ford(vector<vector<int>> &edges, int n){

    vector<int> dist(n+1, INT_MAX);

    dist[0] = 0;
    for(int i=0; i<n-1; i++){
        for(auto it: edges){

            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if(dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
            }

        }
    }

    for(auto it: edges){

            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if(dist[u] + wt < dist[v]){
                cout << "There is negetive edges" << endl;

                return;
            }

    }
    

    cout << dist[n-1];


   


}


signed main(){
    int t;
    cin >> t;

    while(t -- ){
        int n , e;
        cin >>n >> e;

        vector<vector<int> > edgs(e, vector<int>(3) );

        for(int i=0; i<e; i++){
            for(int j=0;j<3;j++){
                cin >> edgs[i][j];
            }
        }

   

        belman_Ford(edgs, n);

    }
    

    
}