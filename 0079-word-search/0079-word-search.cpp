class Solution {
public:
    int dir[5] = {-1,0,1,0,-1};
    bool backtrack(vector<vector<char>>& board, const string& word, int i, int j, int curr){
        if(curr == word.size()) return true;
        if(i<0||j<0||i==board.size()||j==board[0].size() || board[i][j]!=word[curr]) return false;
        board[i][j]='0';
        for(int d=0;d<4;d++){
            if(backtrack(board, word, i+dir[d], j+dir[d+1], curr+1)){
                board[i][j]=word[curr];
                return true;
            } 
        }
        board[i][j]=word[curr];
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size() > board.size() * board[0].size()) return false;
        int occ[128] = {};
        for(const auto &v : board) {for(char c : v) {++occ[c];}}
        for(char c : word) {
            if(--occ[c] < 0) {return false;}
        }
        
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(backtrack(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};