class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if(nums.size() <=2) return nums;
        long long mid = 0;
        for(int x: nums){
            mid ^= x;
        }long long middle = mid & (-mid);
        int first = 0, second = 0;
        for(int x:nums){
            if(middle & x) first ^= x;
            else second ^= x;
        }
        return {first,second};
    }

};


/*class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        //int ans = 0;
        if(nums.size() <=2) return nums;
        sort(nums.begin(),nums.end());
        for(int i =1;i<nums.size();i++){
            if(nums[i-1]==nums[i]) i++;
            else ans.push_back(nums[i-1]);
            if(i==nums.size()-1 && nums[i-1]!=nums[i]) ans.push_back(nums[i]);
        }
        return ans;
    }
};*/