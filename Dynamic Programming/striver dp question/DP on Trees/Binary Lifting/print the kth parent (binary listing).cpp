


/* ques :

Give a tree input and print Q urries for every query , a node X and k will be given print the kth parent of the x node....
example : x=8, and k =2 so node 8's 2nd parent is : 1.... 


            1                       queury:    output:
          /  \  \                       8 2      1
         2   3   4                      7 1      1
           / \ \   \                    10 2     8
          5  6  7   8                   
                     \
                      9
                       \
                       10 

*/



// constrain ---> n <= 10^5
//    Q <= 10^5




// bruteforce --

/*
#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100005];

int nnnnnnn[10005];

void dfs(int node, int parent ){
    //cout << node<< " " <<parent;
    //cout<<endl;
   
    nnnnnnn[node] = parent;
    
    for(auto it: adj[node]){
        if(it != parent){
            dfs(it, node);
           
        }
    }
}
int main(){
    int n;
    cin >> n;

    adj->resize(n+1);

    for(int i=1;i <n; i++){
        int u,v;
        cin >> u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);

   // for(int i=1; i<11; i++){
   //     cout << nnnnnnn[i] <<" ";
   // }

    int query ;
    cin >> query;
    while(query --){    // this may givis TLE Because for dfs--> o(n) and  and for q quries o(Q*K) --overall --> o(n) + o(Q*k)...
        int nd , k;
        cin >> nd >>k;
        int par = nd;
        while(k--){
            par =  nnnnnnn[par] ;
            

        }

        cout<< par <<endl;
    }


}
*/
//if there is 10^5 node in worst case than 2^n parent is --> log(17) base 2  this nerar equl to 17

// Binary Lifting ----

#include<bits/stdc++.h>
using namespace std;

vector<int> adj[10005];

int parent[100005][17];

void dfs(int node, int par ){
    //cout << node<< " " <<parent;
    //cout<<endl;
   
    parent[node][0] = par;

    for(int i=1;i <16;i ++){
        parent[node][i] = parent[parent[node][i-1]][i-1];
    }
    
    for(auto it: adj[node]){
        if(it != par){
            dfs(it, node);
           
        }
    }
}
int main(){
    int n;
    cin >> n;

    adj->resize(n+1);

    for(int i=1;i <n; i++){
        int u,v;
        cin >> u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

   // for(int i=1; i<11; i++){
   //     cout << nnnnnnn[i] <<" ";
   // }

    int query ;
    cin >> query;
    while(query --){    // this may givis TLE Because for dfs--> o(n * 16) and  and for q quries o(Q * log k) --overall --> o(n* 16) + o(Q * log k)...
        int nd , k;
        cin >> nd >>k;
        int p = nd;
        int count = 0;
        while(k){
            if(k & 1){
                p = parent[p][count]; 
            }

            k = k >> 1;           // log k
            count++;
            

        }

        cout<< p <<endl;
    }


}