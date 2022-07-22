// you are given satat and destination point minimum number of multiplication rwquired to reach the destination
// start = 2 , end = 100
// arr[] = {2, 5, 10};
// https://www.geeksforgeeks.org/minimum-steps-to-reach-end-from-start-by-performing-multiplication-and-mod-operations-with-array-elements/
#include<bits/stdc++.h>
using namespace std;

int minOperation(vector<int> &v , int start, int end){
    vector<int> vis(end + 1);
     vis[start] = 1;
    queue<pair<int, int>> q;
    q.push({start, 0});
   
    while(!q.empty()){
        int n = q.front().first;

        int step = q.front().second;

        if(n == end){
            return step;
        }

        q.pop();

        for(int i=0; i<v.size() ; i++){
            int des = n * v[i];
            if(des <= end && !vis[des]){
                q.push({des, step + 1});
                vis[des] = 1;
            }
        }


    }

    return -1;
}

int main(){
    int start, end;
cin >> start >> end;
int n; cin >> n;

    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

   cout <<  minOperation(v, start, end );
}
