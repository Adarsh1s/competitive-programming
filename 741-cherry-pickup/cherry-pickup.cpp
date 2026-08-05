class Solution {
    int n;
    vector<vector<vector<int>>> memo;

    int solve(vector<vector<int>>& grid, int r1, int c1, int r2) {
        int c2 = r1 + c1 - r2;
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n) return -(1 << 30);
        if (grid[r1][c1] == -1 || grid[r2][c2] == -1) return -(1 << 30);

        if (r1 == n - 1 && c1 == n - 1) return grid[r1][c1];

        if (memo[r1][c1][r2] != INT_MIN) return memo[r1][c1][r2];

        int cherries = grid[r1][c1];
        if (r1 != r2 || c1 != c2) cherries += grid[r2][c2];

        int best = -(1 << 30);
        best = max(best, solve(grid, r1 + 1, c1, r2 + 1));
        best = max(best, solve(grid, r1 + 1, c1, r2));
        best = max(best, solve(grid, r1, c1 + 1, r2 + 1));
        best = max(best, solve(grid, r1, c1 + 1, r2));

        memo[r1][c1][r2] = cherries + best;
        return memo[r1][c1][r2];
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        memo.assign(n, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
        return max(0, solve(grid, 0, 0, 0));
    }
};