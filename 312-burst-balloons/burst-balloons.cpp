class Solution {
public:
    vector<int> vals;
    vector<vector<int>> memo;

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vals.resize(n + 2);
        vals[0] = 1;
        vals[n + 1] = 1;
        for (int i = 0; i < n; i++) vals[i + 1] = nums[i];

        int m = n + 2;
        memo.assign(m, vector<int>(m, -1));

        return solve(0, m - 1);
    }

    int solve(int left, int right) {
        // No balloons between left and right
        if (right - left < 2) return 0;
        if (memo[left][right] != -1) return memo[left][right];

        int best = 0;
        for (int k = left + 1; k < right; k++) {
            int coins = vals[left] * vals[k] * vals[right];
            best = max(best, solve(left, k) + coins + solve(k, right));
        }

        memo[left][right] = best;
        return best;
    }
};