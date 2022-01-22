class Solution {
public:
    vector<int> largestSubarray(vector<int>& nums, int k) {
        
        int max_idx =  0;
        
        for(int windows =0; windows <nums.size()-k+1; windows++){
            if(nums[max_idx] < nums[windows]){
                max_idx = windows;
            }
        }
        
        vector<int> ans;
        for(int i=max_idx ;i<max_idx+k; i++){
            ans.push_back(nums[i]);
        }
        return ans;
        
    }
};