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
            int n1 = s.size();
            if(n1>=3){
                int temp = s[1]-s[0];bool a = true;
                for(int i = n1-1;i>1;i--){
                    if(temp != s[i]-s[i-1]) a = false;
                }
                if (a == true) ans++; 
            }
        }
    return ans;
    }
};