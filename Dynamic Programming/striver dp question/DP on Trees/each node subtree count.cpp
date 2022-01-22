/* ques :

Give a tree input and print Q urries for every query , a node X will be given print the no of nodes under the node X..... 


            1                       queury:    output:
          /  \  \                       3       4
         2   3   4                      8       3
           / \ \   \                    1       10
          5  6  7   8                   
                     \
                      9
                       \
                       10 

*/

#include<bits/stdc++.h>
using namespace std;

vector<int> adj[10005];

int subtree[10005];
//int even_ct[10005];  // for even node present in subtree
void dfs(int node, int parent ){
    //cout << node<< " " ;
   /* if(node%2 ==0){
        even_ct[node] = 1;    // // for even node present in subtree
    }
    */
    subtree[node] = 1;
    for(auto it: adj[node]){
        if(it != parent){
            dfs(it, node);
            subtree[node] += subtree[it];
            //even_ct[node] += even_ct[it];  // for even node present in subtree
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

    int query ;
    cin >> query;
    while(query --){
        int k;
        cin >> k;
        cout << subtree[k]  << endl;
    }


}