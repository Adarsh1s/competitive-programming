class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9],cols[9],boxes[9];
        for(int i =0;i<9;i++){
            for(int j =0;j<9;j++){
                if(board[i][j]=='.') continue;

                char digit = board[i][j];
                int bidx = (i/3)*3+(j/3);
                
                if(rows[i].count(digit) || cols[j].count(digit)
                || boxes[bidx].count(digit)) return false;

                rows[i].insert(digit);
                cols[j].insert(digit);
                boxes[bidx].insert(digit);
            }
        }
        return true;
    }
};

/*class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int s = 9;
        for(int j = 0;j<s;j++){
            unordered_map<int,int> map{{9,0}};
            for(int i = 0;i<s;i++){
            if (board[i][j]=='.') continue;
            else if(map.contains(board[i][j])) return false;
            else map[board[i][j]]++;
            }
        }
        for(int i = 0;i<s;i++){
            unordered_map<int,int> map{{9,0}};
            for(int j = 0;j<s;j++){
            if (board[i][j]=='.') continue;
            else if(map.contains(board[i][j])) return false;
            else map[board[i][j]]++;
            }
        }
        for(int i = 0;i<3;i++){
            for(int j =0;j<3;j++){
                unordered_map<int,int> map{{9,0}};
                for(int r = i * 3;r<i*3+3;r++){
                    for(int c = j * 3;c<j*3+3;c++){
                        if (board[r][c]=='.') continue;
                        else if(map.contains(board[r][c])) return false;
                        else map[board[r][c]]++;
                    }
                }
            }
        }
        
        
        return true;
    }
};*/