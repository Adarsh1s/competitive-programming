class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxsum = nums[0],currsum = nums[0];
        int minsum = nums[0],currmin = nums[0];
        int total = nums[0];
        for(int i = 1;i<nums.size();i++){
            currsum = max(nums[i],currsum + nums[i]);
            maxsum = max(maxsum,currsum);
            
            currmin = min(nums[i],currmin + nums[i]);
            minsum = min(minsum,currmin);
            total += nums[i];
        }
        if(maxsum<0) return maxsum;
        return max(maxsum,total - minsum);
    }
};