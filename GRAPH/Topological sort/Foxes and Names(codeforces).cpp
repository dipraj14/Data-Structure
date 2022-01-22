


// ques:https://codeforces.com/contest/510/problem/C



#include<bits/stdc++.h>
using namespace std;
 vector<int> adj[26];
vector<int> vis(26);
vector<int>indegree(26);

// topologigal sort possible only Directed graph

void Khans_Algo_topoSort_BFS (int n ) {
    // trivers through all the edges of the graph
     for(int i=0; i<n ; i++){
         //i -> it 
         for(auto it: adj[i]){
             indegree[it] ++;
         }
     }
     queue<int> q;

     for(int i=0; i<n; i++){
         if(indegree[i] == 0){
             q.push(i);
         }
     }

     vector<int> topoSort;

     while(!q.empty()){
         int node = q.front();
         q.pop();

         topoSort.push_back(node);
        // remove all the edges that originate fromm this 0 indegree
        // node -> it
         for(auto it: adj[node]){
             indegree[it]--;
             if(indegree[it] == 0){
                 q.push(it);
             }
         }

     }


     for(auto it: topoSort){
         cout << char(it+'a' );
     }

   
}

bool cycleDetect(int node){
    vis[node] = 2;

    for(auto it: adj[node]){
        if(!vis[it]){

            if(cycleDetect(it)) {

                return true;

            } 


        }
        else if(vis[it] == 2){

            return true;

        }
    }

    vis[node] = 1;

    return false;
}

char getInd(char c){
    return c-'a';
}

int main(){
	int n;
    cin >> n;
    vector<string> vec;

    for(int i=0;i <n; i++){
        string s;
        cin >>s ;
        vec.push_back(s);
    }

   
    for(int i=0; i<n-1; i++){
        string s1 = vec[i];
        string s2 = vec[i+1];

        for(int j=0; j<s1.size(); j++){
            if(j >= s2.size()){
                cout << "Impossible" << endl;
                return 0;
            }

            if( s1[j] != s2[j]){
                adj[getInd(s1[j])]. push_back(getInd(s2[j]));
                break;
            }
        }


    }

    for(int i=0; i<26; i++){
        if(vis[i] == 0){
            if(cycleDetect(i)){
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }

    set<char> st;

    for(int i=0; i<vec.size();i++){
        string s = vec[i];
        for(int j=0; j< s.size(); j++){
               if(st.find(s[j]) == st.end()){
                   continue;
               }
               else{

                   st.insert(s[j]);

               }
        }
    }

    Khans_Algo_topoSort_BFS(26);
}  

