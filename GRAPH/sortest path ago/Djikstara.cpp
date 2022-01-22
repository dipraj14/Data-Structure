#include<bits/stdc++.h>
using namespace std;
#define int long long int
vector<pair<int,int>> adj[100010];
vector<int> parent(100010);

void printpath(int n)
{
    if(n!=1)
        printpath(parent[n]);
    printf("%d ",n);
}

void dijkstra(int src, int n){

    priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>  > pq; // min prirotity pueue

    vector<int> dist(n+1 ,0);

    for(int i=1; i<=n; i++){
        dist[i] = LONG_LONG_MAX;
    }

    dist[src] = 0;
    
    int flag =0;

    pq.push({0, src});
    parent[src] = src;

    while(!pq.empty()){

        int dis = pq.top().first;
        int node = pq.top().second;

        //cout<< dis <<" " << node<< endl;

        
            pq.pop(); // both are valid dq.push_back or dq.push_front()
    
        
            //dq.pop_back();
         

        for(auto it : adj[node]){
            int adjNode = it.first;
            int wt = it.second;

            if(dis + wt < dist[adjNode]){
                dist[adjNode] = dis + wt;
              // cout<< dis+wt <<" " << adjNode <<" " << endl;
                pq.push({ dis + wt, adjNode});

                parent[it.first] = node;
   
            } 
        }

    }

   // print the sortest distance of every node

    //for(int i=1; i<=n ;i++){
    //    cout << parent[i] <<" ";
   // }


   // print the path
   if(dist[n] == LONG_LONG_MAX){
       cout<< -1 << endl;
       return;
   }

   printpath(n);


}


signed main(){
    int n , e;
    cin >>n >> e;

    for(int i=0; i<e; i++){
        int u, v , w;

        cin >> u >> v >>w ;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    dijkstra(1, n);
}