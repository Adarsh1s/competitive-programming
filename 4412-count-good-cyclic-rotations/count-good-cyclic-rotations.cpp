class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();int ans = 0;
        long long first = 0,second = 0; int mid = n / 2;

        vector<int> d_nums=nums;
        d_nums.insert(d_nums.end(),nums.begin(),nums.end());
        for(int i = 0;i<n;i++){
            if(i<mid) first += nums[i];
            else second += nums[i];
        }
        if(first>second) ans++;
        for(int i = 1;i<n;i++){
            first = first-d_nums[i-1]+d_nums[i+mid-1];
            second = second-d_nums[i+mid-1]+d_nums[i+n-1];

            if(first>second) ans++;
        }
        return ans;
    }
};