#include <bits/stdc++.h>
using namespace std;
 

int count_subset(int set[], int n, int sum)
{
   
    // Base Cases
    if (sum == 0)
        return 1;
    if (n == 0)
        return 0;
 
    // If last element is greater than sum,
    // then ignore it
    if (set[n - 1] > sum)
        return count_subset(set, n - 1, sum);
 
    /* else, check if sum can be obtained by any
of the following:
      (a) including the last element
      (b) excluding the last element   */

    return count_subset(set, n - 1, sum) + count_subset(set, n - 1, sum - set[n - 1]);
}
 

void starter(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}


int main()
{

    //starter();
    int n;
    cin >>n;

    int set[n];
    for(int i=0;i<n;i++){
        cin >> set[i];
    }
    int sum;
    cin>> sum;

    int count = count_subset(set, n, sum);
    
    if(count > 0){
         cout <<"no of subsent which is equal to given sum: " << count  ;
    }
    else{
        cout <<"No subset with given sum: " << count;
    }
    return 0;
}