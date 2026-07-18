class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int dir = 1;
        //last
        int n = matrix.size();
        int m = matrix[0].size();
        int total_elements = n*m;
        //first
        int s_row=0;
        int s_col=0;
        int i=0, j=0;
        while(ans.size() != total_elements){
            //right
            while(j<m && ans.size() < total_elements){
                ans.push_back(matrix[i][j]);
                j++;
            }
            j--;
            s_row++;
            i++;
            //down
            while(i<n && ans.size() < total_elements){
                ans.push_back(matrix[i][j]);
                i++;
            }
            i--;
            m--;j--;
            //left
            while(j>=s_col && ans.size() < total_elements){
                ans.push_back(matrix[i][j]);
                j--;
            }
            n--;j++;
            i--;
            //up
            while(i>=s_row && ans.size() < total_elements){
                ans.push_back(matrix[i][j]);
                i--;
            }
            j++;i++;
            s_col++;
        }
        return ans;
    }
};