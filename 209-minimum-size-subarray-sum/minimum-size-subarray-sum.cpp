class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int curSum=0,minSum=INT_MAX;
        int left =0,sum=0;
        for(int right = 0;right<nums.size();right++){
            if(sum==target) minSum = min(right-left+1,minSum);
            sum += nums[right];
            

            while(sum >= target){
                minSum = min(right-left+1,minSum);
                sum -= nums[left];
                left++;
            } 
            
        }
        return minSum==INT_MAX? 0:minSum;
    }
};