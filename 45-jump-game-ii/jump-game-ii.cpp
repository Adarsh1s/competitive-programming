class Solution {
public:
    int jump(vector<int>& nums) {
        int index = 0;
        vector<int> map(nums.size(),INT_MAX);

        for(int i = 0;i<nums.size();i++){
            if(i == 0) map[0] = 0;
            index = nums[i]+i;
            long long temp = map[i];
            for(int j = i;j<=index&&j<nums.size();j++){
                if (map[i] == INT_MAX) continue;
                map[j] = min(temp+1,static_cast<long long>(map[j]));
            }
        }
        return map[nums.size()-1];
    }
};