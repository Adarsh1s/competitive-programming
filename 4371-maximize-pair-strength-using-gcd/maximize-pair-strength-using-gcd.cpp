class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long ans = 0;
        for(int i = 0;i<nums.size();i++){
            for(int j = 0;j<nums.size();j++){
                long long a = nums[i];
                long long b = nums[j];
                long long g = gcd(a,b);
                long long strength = (a*b)/(g*g);
                ans = max(ans,strength);
            }
        }
        return ans;
    }
};