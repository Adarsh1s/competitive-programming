class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,vector<int>> map(n);
        for(int i = 0;i<n;i++){
            map[nums[i]].push_back(i);
        }
        int ans = 0;
        for(const auto& [f,s] : map){
            if(s.size()==3){
                if(s[1]-s[0]==s[2]-s[1]) ans++;  
                
            }
        }
    return ans;
    }
};