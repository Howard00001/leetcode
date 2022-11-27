class Solution {
public:
    int dir[5] = {-1,0,1,0,-1};
    bool backtrack(vector<vector<char>>& board, string word, int i, int j, int curr){
        if(curr == word.size()) return true;
        if(i<0||j<0||i==board.size()||j==board[0].size()) return false;
        if(board[i][j]!=word[curr]) return false;
        // cout<<board[i][j];
        bool track=false;
        char tmp = board[i][j];
        board[i][j]='0';
        for(int d=0;d<4;d++){
            track = track || backtrack(board, word, i+dir[d], j+dir[d+1], curr+1);
        }
        board[i][j]=tmp;
        return track;
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool track=false;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                track = track || backtrack(board, word, i, j, 0);
            }
        }
        return track;
    }
};