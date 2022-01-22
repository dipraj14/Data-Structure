
// Question : Seating Arrangement

// link : https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/seating-arrangement-6b8562ad/

#include <bits/stdc++.h>


#define int long long int
using namespace std;

// its work onli 1 to n-1 array

void seatingArrangment(){

    int n, persion;
    string preference;
    cin >> n >> persion;
    cin >> preference;
    

    map<int,int> chairMap;

    priority_queue<pair<int,int> > pq;


    pq.push({n,-1});

    for(int i=1; i<=persion; i++){

        int len = pq.top().first;
        int start = -1* pq.top().second;

        pq.pop();

        int end = start + len -1;
        int mid = (start + end) / 2;

        if(preference[i-1] == 'R' && len % 2 == 0){
            mid += 1;
        }

        chairMap[mid] = i;

        //break them two part

        if(start != mid){
            pq.push({ mid - start, -1 * start});
        } 

        if(end != mid){
            pq.push( {end - mid, -1 * (mid+1) } );
        }


    }

    int q;
    cin >> q;

    while(q--){
        int chairno;
        cin >> chairno;

        if(chairMap.find(chairno) == chairMap.end()){
            cout<< "-1" <<endl;
            
        }
        else{
            cout<< chairMap[chairno] << endl;
        }
    }


      
      
 }

signed main()
{   
  

   seatingArrangment();
  
  
}