class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0;int max1=0;int maxlen=0;
        unordered_map<int,int> map;
        for(int right = 0;right<nums.size();right++){
            if(nums[right]==1) map[nums[right]]++;
            max1 = max(max1,map[nums[right]]);

            if((right-left+1)-max1>k){
                map[nums[left]]--;
                left++;
            }
            maxlen=max(maxlen,right-left+1);
        } 
        return maxlen;
    }
};