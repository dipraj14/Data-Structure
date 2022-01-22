#include<bits/stdc++.h>
using namespace std;


void add_edge(vector<vector<int>> &g, int u, int v){
    g[u].push_back(v);
    g[v].push_back(u);
}

void print_list(vector<vector<int>> &AdjList){

    for (int i = 0; i < AdjList.size(); i++)
    {
        cout << i;
        for(int j = 0; j < AdjList[i].size(); j++)
        {
            if(j == AdjList[i].size() - 1)
            {
                cout << " -> " << AdjList[i][j] << endl;
                break;
            }
            else
                cout << " -> " << AdjList[i][j];
        }
    }
}

int main(){


    int v;
    cin >> v;

    vector<vector<int>> g(v);  // 0 1 2 3 4

    add_edge(g, 0 , 1);
    add_edge(g, 0 , 4);
    add_edge(g, 1 , 2);
    add_edge(g, 1 , 3);
    add_edge(g, 1 , 4);    //           4
    add_edge(g, 2 , 3);     //          |
    add_edge(g, 3 , 4);     //    0 ---_1 ----2 --- 3 -- 4    // for detail pic--> https://www.geeksforgeeks.org/graph-implementation-using-stl-for-competitive-programming-set-1-dfs-of-unweighted-and-undirected/
                            //          |
                           //           |
                            //          3

   print_list(g);


}