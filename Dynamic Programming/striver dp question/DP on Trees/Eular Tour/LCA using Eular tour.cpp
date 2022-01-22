
// constrain ---> n <= 10^5
//    Q <= 10^5

/*   

           1                    query:      output:
        /  \  \                     3
       2    3   4                 5 7         3
            / \                   2 5         1
           5   6                  6 7         6
                \
                 7

*/



#include<bits/stdc++.h>
using namespace std;

vector<int> adj[10005];

//int parent[2* 100005];       // log(100005) near equl to 16 // so we take 17 size
vector<int> parent;
int level[100005];

map<int,int> mp;

void dfs(int node, int par, int lev = 0 ){          // Binary Lifting   // complixity- > o(n * 16)  // or o(n * log(n)(base 2))
    //cout << node<< " " <<parent;
    //cout<<endl;

    parent.push_back(node);
    
   
    for(auto it: adj[node]){
        if(it != par){
            dfs(it, node, lev+ 1);
             parent.push_back(node);
        }
       
    }
}

void hasing(){

     for(int i=0;i <parent.size(); i++){

       if(mp.find(parent[i]) == mp.end()){
           mp[parent[i]] = i;
       }
       else{
           continue;
       }

   }

}



int LCA_using_Eular_Tour(int u, int v){    // for map -- > o(r - l + 1)  // if we use segmentree than this much is also redude to log n

   
   int l = mp[u];
   int r = mp[v];

   int mini = INT_MAX;

   for(int i=l; i<=r;i++){
       mini = min(mini, parent[i]);
   }

   return mini;



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

    hasing();


    int query ;
    cin >> query;
    while(query --){    // for q query --- >  Q *  (r - l + 1)
        int n1, n2;   
        cin >> n1 >> n2;

        cout << LCA_using_Eular_Tour(n1, n2) << endl;      
    }

    



  



}