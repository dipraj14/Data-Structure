
#include<bits/stdc++.h>
using namespace std;
// topologigal sort possible only Directed graph


vector<int>adj[100005];

vector<bool> vis(100005);
vector<int>ans;

void dfs(int node,stack<int> &st ) {

        //ans.push_back(node); 

        vis[node] = 1; 
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(it, st); 
                //st.push( it);
            }

            
        }

      st.push(node);

   
}

void dfsOfGraph(int V){
	     

	    //vector<int> vis(V+1, 0); 

        stack<int> st;

      for(int i = 1; i<= V ;i++) {
        if(!vis[i]) {
            dfs(i,st); 
        }
      }
     // st.push(1);

       while(!st.empty()){
            cout << st.top() <<" ";
            st.pop();
        }
	    
}



int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	adj->resize(V+1);
   

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		//adj[v].push_back(u);
    	}
      
       dfsOfGraph(V);
       
       // for(int i=1;i <=V;i++){
        //	cout << ans[i] <<" ";
        //}
       // cout<<endl;

      
	}
	return 0;
}  

