class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        for(int i =0;i<n;i++){
            while(rowShift[i]>0){
                rowShift[i]--;
                for(int j =0;j<n-1;j++){
                    swap(grid[i][j],grid[i][j+1]);
                }
            }
        }
        for(int i =0;i<n;i++){
            while(colShift[i]>0){
                colShift[i]--;
                for(int j =0;j<n-1;j++){
                    swap(grid[j][i],grid[j+1][i]);
                }
            }
        }
        return grid;
    }
};