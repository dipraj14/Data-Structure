 #include <bits/stdc++.h>
#define endl "\n"
using namespace std;

//#define int long long int


vector<vector<bool>> vis;
int n ,  m ;

vector<pair<int,int>> moves = {{-1,0}, {1,0}, {0,-1}, {0,1}};

vector<vector<pair<int,int>> > path;

int sx,sy,ex,ey;


bool isValid(int x, int y)
{
	if(x<0 or x >= n or y <0 or y>=m)
		return false;
	if(vis[x][y])
		return false;
	return true;
}

void bfs( ){

    queue<pair<int,int> > pq;
    pq.push({sx,sy});

    while(!pq.empty()){
        int cx = pq.front().first;
        int cy = pq.front().second;
        pq.pop();

        for(auto mv: moves){
            int mvx = mv.first;
            int mvy = mv.second;

            if(isValid(cx+mvx, cy+mvy)){

                pq.push({cx+mvx, cy+mvy});  // push for all the adjency

                vis[cx+mvx][cy+mvy] = true;

                path[cx+mvx][cy+mvy] = {mvx,mvy};  // strore the path for each moves
            }
        }
    }



}


int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);



    cin >> n >> m;
    path.resize(n);

    vis.resize(n);

    for(int i = 0; i < n; ++i)
	{
        path[i].resize(m);
		vis[i].resize(m);
	}
	
    

    for(int i=0 ;i<n;i++){

        for(int j=0; j<m ;j++){

            path[i][j]={-1,-1};

             char c;

             cin >> c;

            if(c == '#'){

                vis[i][j] = true;
            }
        
        }
    }
    int max_time;
    cin >> max_time;
    
    sx =0;
    sy =0;
	ex = n-1;
	ey = m-1;

    bfs();

    if(!vis[ex][ey]){
        cout<<"NO" <<endl;
        return 0;
    }
    //cout<< "YES" << endl;

    vector<pair<int,int> > ans;

    pair<int,int> end = {ex,ey};


    while(end.first != sx || end.second != sy){

        ans.push_back( path[end.first][end.second] );

        end.first -= ans.back().first;
        end.second -= ans.back().second;
    }

    reverse(ans.begin(), ans.end());
        
    int k =  ans.size();
    if( k <= max_time){
       cout<< "YES"<<endl;
    }


    


	 
}