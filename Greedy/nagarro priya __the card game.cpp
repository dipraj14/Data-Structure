#include<bits/stdc++.h>
using namespace std;

int minSubarray_Sum(vector<int> &input2, int input1) {
    
     int tsum = 0;
    for (int i = 0; i < input1; i++) {
     
        tsum += input2[i];
    }
    
    int min_sum = INT_MAX;
    
    int curSum = 0;
    
    for (int i = 0 ; i < input1; i++) {
        curSum = curSum + input2[i];
        if (curSum < min_sum)
            min_sum = curSum;
        if (curSum > 0)
            curSum  = 0;
    }

     int ans = (tsum- min_sum)+min_sum * (-1);
     return ans;
}

int main() {
    
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        
    }
    cout<< minSubarray_Sum(a, n);
    
    
    
   

}