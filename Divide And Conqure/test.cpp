
#include <bits/stdc++.h>

using namespace std;


int minSubArrayLen(int target, vector<int>& nums) {
        
        int n = nums.size();
        
        int sum =0;
        
        int min_len = n+1;
        int start=0, end=0;
      while(end<n){
          
       
            while(sum <= target && end <n){
            
                sum += nums[end++];
            
            }
            while(sum > target && start< n){
                if(end-start < min_len){
                    min_len = end - start;
                }
            }
            sum -= nums[start++];
      }
        
        if(min_len == INT_MAX){
            return 0;
        }
        else{
            return min_len;
        }
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n) ;

    for(int i=0 ;i < n; i++){
        cin >> nums[i];
    }
    
    int target;
    cin >> target;
    
    cout<< minSubArrayLen(target, nums);

        
        
        
        
    
}
