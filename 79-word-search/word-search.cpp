class Solution {
    string ans;
private:
    bool dfs(vector<vector<char>>& board,string word,int n,int m,int i,int j,char idx){
        if(idx == word.size()) return true;
        if(i<0 || j<0 || i>=n || j>=m || board[i][j] != word[idx]) return false;
        
        //if(board[i][j] == word[idx]){
            char temp =  board[i][j];
            board[i][j] = '0';
        //}
        bool ans = dfs(board,word,n,m,i+1,j,idx+1) ||
        dfs(board,word,n,m,i-1,j,idx+1) ||
        dfs(board,word,n,m,i,j+1,idx+1) ||
        dfs(board,word,n,m,i,j-1,idx+1);

        board[i][j] = temp;
        return ans;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        
        for(int i = 0;i<n;i++){
            for(int j =0;j<m;j++){
                if(board[i][j] == word[0]){
                    if(dfs(board,word,n,m,i,j,0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};