
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

#define int long long int




vector<pair<int,int>> moves = {{-1,0}, {1,0}, {0,-1}, {0,1}};


bool isValid(int x, int y, int n ,int m, vector<vector<bool>> &vis)
{
	if(x<0 or x >= n or y <0 or y>=m)
		return false;
	if(vis[x][y])
		return false;
	return true;
}

void dfs(int i , int j, vector<vector<bool>> &vis, int n ,int m){

    vis[i][j] = true;

    for(auto it: moves){
        if( isValid(i + it.first, j + it.second, n , m, vis) ){

            dfs(i + it.first, j + it.second, vis, n , m);

        }
    }





}


void connectedComponent(vector<vector<bool>> &vis, int n, int m, int rooms){

    for(int i=0 ;i<n ;i++){

        for(int j=0; j<m ;j++){

            if(!vis[i][j]){

                dfs(i,j, vis, n,  m);

                ++rooms;

            }
        }
    }


    cout<< rooms <<endl;


}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n,m,rooms;

    cin >> n >> m;
    rooms = 0;

  //  vector<vector<char>> v(n, vector<char> (m));

    vector<vector<bool>> vis(n, vector<bool> (m) );

    for(int i=0 ;i<n;i++){

        for(int j=0; j<m ;j++){
            char c;

            cin >> c;

            if(c == '#'){

                vis[i][j] = true;
            }
        }
    }

    connectedComponent(vis, n ,m, rooms);

    





	 
}




/*
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

#define int long long int


vector<vector<bool>> vis;
int n ;
 int m , rooms;

vector<pair<int,int>> moves = {{-1,0}, {1,0}, {0,-1}, {0,1}};


bool isValid(int x, int y)
{
	if(x<0 or x >= n or y <0 or y>=m)
		return false;
	if(vis[x][y])
		return false;
	return true;
}

void dfs(int i , int j){

    vis[i][j] = true;

    for(auto it: moves){
        if( isValid(i + it.first, j + it.second) ){

            dfs(i + it.first, j + it.second);

        }
    }





}


void connectedComponent(){

    for(int i=0 ;i<n ;i++){

        for(int j=0; j<m ;j++){

            if(!vis[i][j]){

                dfs(i,j);

                rooms++;

            }
        }
    }


   


}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);



    cin >> n >> m;

    vis.resize(n);

    for(int i = 0; i < n; ++i)
	{
		vis[i].resize(m);
	}

   // vector<vector<char>> v(n, vector<char> (m));

    

    for(int i=0 ;i<n;i++){

        for(int j=0; j<m ;j++){

             char c;

             cin >> c;

            if(c == '#'){

                vis[i][j] = true;
            }
        }
    }

    connectedComponent();  // n ,m, vis, rooms globally 

    
     cout<< rooms <<endl;




	 
}

*/