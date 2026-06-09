class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> ans(2);
        int n = nums.size();
        for(int i = 0;i<n;i++){ 
            if(map.contains(target-nums[i])) {
                ans[0] = map[target-nums[i]];
                ans[1]=i;
                return ans;
            } 
            map[nums[i]]=i;
        }
        return {};
    }
};