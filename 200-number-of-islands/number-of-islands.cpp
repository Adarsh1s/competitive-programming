class Solution {
private:
    void dfs(vector<vector<char>>& grid,int n,int m,int s,int e){
        if(s<0 || e<0 || s>=n || e>=m || grid[s][e] == '0') return;
        grid[s][e] = '0';
        dfs(grid,n,m,s+1,e);
        dfs(grid,n,m,s-1,e);
        dfs(grid,n,m,s,e+1);
        dfs(grid,n,m,s,e-1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] =='1') ans++;
                dfs(grid,n,m,i,j);
            }
        }
        return ans;
    }
};