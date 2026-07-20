class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1=nums[0];
        int min1=nums[0];
        int result=nums[0];
        for(int i = 1;i<nums.size();i++){
            int temp_max = max({nums[i],max1 * nums[i],min1 * nums[i]});
            int temp_min = min({nums[i],max1 * nums[i],min1 * nums[i]});

            max1 = temp_max;
            min1 = temp_min;
            result = max(result,max1);
        }
        return result;
    }
};