class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            set<int> row, col;
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(row.count(board[i][j])) return false;
                    row.insert(board[i][j]);
                }
                if(board[j][i]!='.'){
                    if(col.count(board[j][i])) return false;
                    col.insert(board[j][i]);
                }
            }
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                set<int> box;
                for(int x=0;x<3;x++){
                    for(int y=0;y<3;y++){
                        if(board[i*3+x][j*3+y]!='.'){
                            if(box.count(board[i*3+x][j*3+y])) return false;
                            box.insert(board[i*3+x][j*3+y]);
                        }
                    }
                }
            }
        }
        return true;
    }
};