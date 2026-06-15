class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans =0;long long temp =0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == 0) temp++;
            else {
                ans += ((temp+1)*(temp))/2;
                temp=0;
            }    
        }
        ans += ((temp+1)*(temp))/2;
        return ans;
    }
};