class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int result = 0;int map[101] = {0};
        for(int i = 0;i<nums.size();i++){
            if(map[nums[i]] > 0) {
                result += map[nums[i]];
                map[nums[i]]++;
            } 
            else map[nums[i]]++;
        }
        return result;
    }
};