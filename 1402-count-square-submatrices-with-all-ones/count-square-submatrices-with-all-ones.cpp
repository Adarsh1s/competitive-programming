class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(),n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int> (n,0));
        int s = 0;
        for(int i = 0;i<m;i++){
            if(matrix[i][0]==0) continue;
            else {
                s++;
                dp[i][0] = 1;
            }
        }
        for(int i = 1;i<n;i++){
            if(matrix[0][i]==0) continue;
            else {
                s++;
                dp[0][i] = 1;
            }
        }
        for(int i = 1;i<m;i++){
            for(int j = 1;j<n;j++){
                if(matrix[i][j] == 0) continue;
                dp[i][j] = matrix[i][j] + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                s += dp[i][j];
            }
        }
        return s;
    }
};