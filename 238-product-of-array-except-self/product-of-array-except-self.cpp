class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        int leftix=1,rightix=1;
        for(int i = 0;i<nums.size();i++){
            ans[i] = leftix;
            leftix *= nums[i]; 
        }
        for(int i = nums.size()-1;i>=0;i--){
            ans[i] *= rightix;
            rightix *= nums[i]; 
        }
        return ans;
    }
};