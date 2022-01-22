
//  foe sortest path algo check graph 4 by striver ..... https://www.youtube.com/watch?v=7K4qjtDwOQo
// and also check unaccademy graph algo 2


#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj[100005];


void Zero_One_Bfs(int src, int n){

    deque<pair<int,int> > dq;

    vector<int> dist(n+1 ,0);

    for(int i=1; i<=n; i++){
        dist[i] = INT_MAX;
    }

    dist[src] = 0;
    
    int flag =0;

    dq.push_front({src, 0});

    while(!dq.empty()){

        int node = dq.front().first;
        int dis = dq.front().second;

        
            dq.pop_front(); // both are valid dq.push_back or dq.push_front()
    
        
            //dq.pop_back();
        

        for(auto it : adj[node]){
            int adjNode = it.first;
            int wt = it.second;

            if(dis + wt < dist[adjNode]){
                dist[adjNode] = dis + wt;

                if(wt == 1){
                    dq.push_back({adjNode,dis + wt});
                    flag = 1;
                }
                else{
                     dq.push_front({adjNode, dis + wt});
                     flag = 0;

                }
            } 
        }

    }


    for(int i=1; i<=n ;i++){
        cout << dist[i] <<" ";
    }


}


int main(){
    int n , e;
    cin >>n >> e;

    for(int i=0; i<e; i++){
        int u, v , w;

        cin >> u >> v >>w ;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    Zero_One_Bfs(1, n);
}