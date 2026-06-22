class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        int s = nums.size();
        for(int i = 0;i<s-2;i++){
            if(nums[i]>0) break;
            if(i>0 && nums[i]== nums[i-1]) continue;
            int low = i+1,high = s-1;  
            while(low<high){
                int sum = nums[i] + nums[low] + nums[high];
                if(sum<0) low++;
                else if(sum>0) high--;
                else {
                    result.push_back({nums[i],nums[low],nums[high]});
                    while(low < high && nums[low] == nums[low+1]) low++;
                    while(low < high && nums[high] == nums[high-1]) high--;
                    low++;
                    high--;

                }
            }
        }
        return result;
    }
};