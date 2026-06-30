class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int ans = 0;int temp = 0;
        //vector<int> temp(nums.size()+1);
        sort(nums.begin(),nums.end());
        for(int i = 0;i<nums.size()-1;i++){
            temp=nums[i+1]-nums[i];
            ans = max(temp,ans);
        }
        return ans;
    }
};