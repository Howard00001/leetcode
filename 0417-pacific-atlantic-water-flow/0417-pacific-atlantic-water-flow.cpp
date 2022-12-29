class Solution {
public:
    vector<vector<bool>> pac, atl;
    int m, n;
    void dfs(int i, int j, vector<vector<bool>> &dp, int prev, vector<vector<int>>& heights){
        if(dp[i][j] || heights[i][j]<prev) return;
        dp[i][j] = true;
        prev = heights[i][j];
        if(i+1<m) dfs(i+1,j,dp,prev,heights);
        if(i>0) dfs(i-1,j,dp,prev,heights);
        if(j+1<n) dfs(i,j+1,dp,prev,heights);
        if(j>0) dfs(i,j-1,dp,prev,heights);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        pac = atl = vector<vector<bool>> (m, vector<bool>(n, false));
        for(int i=0;i<m;i++){
            dfs(i,0,pac,-1,heights);
            dfs(i,n-1,atl,-1,heights);
        }
        for(int j=0;j<n;j++){
            dfs(0,j,pac,-1,heights);
            dfs(m-1,j,atl,-1,heights);
        }
        vector<vector<int>> res;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(atl[i][j] && pac[i][j])
                    res.push_back({i,j});
            }
        }
        return res;
    }
};