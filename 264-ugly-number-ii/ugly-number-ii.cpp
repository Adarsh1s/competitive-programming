class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0]=1;
        int a = 0, b = 0, c = 0;
        for(int i = 1;i<n;i++){
            dp[i] = min({dp[a]*2,dp[b]*3,dp[c]*5});

            if(dp[a]*2 == dp[i]) a++;
            if(dp[b]*3 == dp[i]) b++;
            if(dp[c]*5 == dp[i]) c++;
        }
        return dp[n-1];
    }
};