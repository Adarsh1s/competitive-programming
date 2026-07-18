class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        int s = n*m;
        vector<vector<int>> temp{
            {0,1},{1,0},{0,-1},{-1,0},{1,1},{-1,-1},{-1,1},{1,-1}
        };
        vector<vector<int>> use(n, vector<int>(m, 0));
        for(int k = 0;k<s;k++) helper(board,temp,k/m,k%m,n,m,use);
        board = use;
    }
private:
    void helper(vector<vector<int>>& board,vector<vector<int>>& temp,int i,int j,int n,int m,vector<vector<int>>& use){
        int count = 0;
        for(const auto& x:temp){
            int i1 = i + x[0];
            int j1 = j + x[1];
            if(i1>=0 && i1<n && j1>=0 && j1<m){
                if(board[i1][j1] == 1) count++;
            }
            else continue;
        }
        if(count <2) use[i][j] = 0;
        if(count ==2 || count==3) use[i][j]=board[i][j];
        if(count >3) use[i][j] = 0;
        if(count ==3) use[i][j] = 1;
    }
};