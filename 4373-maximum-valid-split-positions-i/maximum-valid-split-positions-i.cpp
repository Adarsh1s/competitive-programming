class Solution {
private:
    int helper(vector<int>& nums){
        int ans = 0;int n = nums.size();
        if(n<=1) return 0;
        
        vector<int> pre_gcd(n),post_gcd(n);
        for(int i = 0;i<n;i++) {
            if(i==0) pre_gcd[i] = nums[i];
            else pre_gcd[i]=gcd(pre_gcd[i-1],nums[i]);
        }

        for(int i = n-1;i>=0;i--) {
            if(i==n-1) post_gcd[i] = nums[i];
            else post_gcd[i]=gcd(post_gcd[i+1],nums[i]);
        }
        
        for(int i = 0;i<n-1;i++){
            if(pre_gcd[i]==post_gcd[i+1]) ans++;
        }
        return ans;
    }
public:
    int maxValidSplits(vector<int>& nums) {
        vector<int> temp = nums;
        int n = nums.size();
        if(n<=1) return 0;

        int max_score = helper(nums);
        for(int i = 0;i<n;i++){
            vector<int> temp;
            temp.reserve(n-1);
            for(int j = 0;j<n;j++){
                if(i != j) temp.push_back(nums[j]);
            }
            max_score = max(max_score,helper(temp));
        }
        return max_score;
    }
};