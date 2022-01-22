

#include <algorithm>
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
 
const ll N = (ll)(2 * 1e5 + 10); 
 
 
vector<ll> v[N]; 
ll subtree[N], level[N];
//ll mark[N]; 
//ll ans; 
 
void dfs(ll node, ll par = -1, ll lev = 0) 
{

    subtree[node] = 1;
	level[node] = lev; 
	//ll cnt = 0; 
 
	for(auto it : v[node])
	{
		if(it==par) continue; 
		dfs(it, node, lev + 1); 
		subtree[node] += subtree[it]; 
	}
 
	
	
}
 
int main(){
 
	ll n,k;
	cin >> n >> k; 
	for(ll i = 1; i < n; i++){
		ll x, y;
		cin >> x >> y;
		v[x].emplace_back(y); 
		v[y].emplace_back(x); 
	}
 
	dfs(1); 
 
	vector< ll > dist; 

	for(ll i = 1; i <= n; i++){
        dist.push_back(level[i] - (subtree[i] - 1));
    } 
 
	sort(dist.begin(), dist.end());
	reverse(dist.begin(), dist.end()); 
    ll ans =0;
	for(ll i = 0; i < k; i++){
        ans += dist[i];
    }
	cout << ans; 
}




/*
#include<bits/stdc++.h>
using namespace std;

#define long long int int;
 
const int N = (int)(2 * 1e5 + 10); 

vector<int> adj [N];

vector<int> subtree(N);
vector<int> level(N);

void dfs(int node, int parent, int lev ){
    //cout << node<< " " ;

    subtree[node] = 1;

    level[node] = lev;

    for(auto it: adj[node]){
        if(it != parent){
            dfs(it, node, lev + 1);
            subtree[node] += subtree[it];
        }
    }
}
signed main(){
    int E ;
    cin >> E ;

    int k;
    cin >> k;

    //adj->resize(E+1);

    for(int i=1;i < E; i++){
        int u,v;
        cin >> u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1, 0);
  vector<int> contri;
  

    for(int i=1; i<=E; i++){
        cout<< level[i] << " ";
    }
    

    cout << endl;
    for(int i=1; i<=E; i++){
        cout<< subtree[i] << " ";
    }
    cout << endl;
    

    for(int i=1; i<=E; i++){
        contri.push_back( level[i] - (subtree[i] - 1) );
    }
    

     for(auto it: contri){
        cout << it <<" ";
    }
    
  // sort(contri.begin(),contri.end());
  // reverse(contri.begin(),contri.end());
   for(auto it: contri){
        cout << it <<" ";
    }
    
   //priority_queue<int> pq;

   for(int i=0 ;i< contri.size() ;i++){
      pq.push(contri[i]);
   }
   
   
    //for(int i=0; i < contri.size(); i++){
    //    pq.push( contri[i]);
    //}

    int sum =0;

    //int s = contri.size()-1;

    for(int i=0; i<k; i++){
        sum+= contri[i];
    }
    while(k--){
        sum+= pq.top();
        pq.pop();
        //sum += contri[s];
        //s--;
    }

   // cout << sum << endl;


//}
*/


