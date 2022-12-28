class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        if not heights: 
            return [[]]
        
        m, n = len(heights), len(heights[0])
        res, dp = [], [0] * (m * n)
        
        def dfs(i, j, ap, prev):
            ij = i * n + j
            if dp[ij] & ap or heights[i][j] < prev: return
            dp[ij] += ap
            prev = heights[i][j]
            if dp[ij] == 3: res.append([i,j])
            if i + 1 < m: 
                dfs(i+1, j, ap, prev)
            if i > 0: 
                dfs(i-1, j, ap, prev)
            if j + 1 < n: 
                dfs(i, j+1, ap, prev)
            if j > 0: 
                dfs(i, j-1, ap, prev)
                
        for i in range(m):
            dfs(i, 0, 1, -1)
            dfs(i, n-1, 2, -1)
        for j in range(n):
            dfs(0, j, 1, -1)
            dfs(m-1, j, 2, -1)
        return res