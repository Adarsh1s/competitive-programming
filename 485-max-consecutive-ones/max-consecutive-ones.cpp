class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max1 = 0,temp = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 1) {
                temp++;
            }
            else{
                max1 = max(max1,temp);
                temp = 0;
            }
        }
        return max(max1,temp);
    }
};