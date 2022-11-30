class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                transform(board, i, j);
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==2) board[i][j] = 0;
                if(board[i][j]==3) board[i][j] = 1;
            }
        }
    }
    
    int dir[9] = {-1,0,1,0,-1,-1,1,1,-1};
    
    void transform(vector<vector<int>>& board, int i, int j){
        int count =0;
        for(int d=0;d<8;d++){
            int x=i+dir[d],y=j+dir[d+1];
            if(x<0||y<0||x>=board.size()||y>=board[0].size()) continue;
            if(board[x][y]==1||board[x][y]==2) count++;
        }
        if(board[i][j]==0 && count==3) board[i][j] = 3;
        if(board[i][j]==1 && (count<2 || count>3)) board[i][j]=2;
    }
};