class Solution {
public:
    bool canJump(vector<int>& nums) {
        int index = 0;
        for(int i = 0;i<nums.size();i++){
            if(i>index) break;
            if(index >= nums.size()-1) return true;
            index = max(index,nums[i]+i);
        }
        return false;
    }
};