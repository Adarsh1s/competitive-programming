class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        map[0]=1;int c = 0;

        int rem=0,total=0;

        for(int i = 0;i<nums.size();i++){
            total += nums[i];
            rem = ((total %k)+k)%k;
            c += map[rem];
            map[rem]++;
        }
        return c;
    }
};