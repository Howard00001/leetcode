class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        if not heights:
            return [[]]
        m, n = len(heights), len(heights[0])
        dp = [[[0 for i in range(n)] for j in range(m)], [[0 for i in range(n)] for j in range(m)]]
        
        # pa 1: pacific, pa 2: atlantic
        def dfs(pa, i, j, prev):
            if dp[pa][i][j] or heights[i][j]<prev:
                return
            dp[pa][i][j] = True
            prev = heights[i][j]
            if i+1<m:
                dfs(pa,i+1,j,prev)
            if i-1>=0:
                dfs(pa,i-1,j,prev)
            if j+1<n:
                dfs(pa,i,j+1,prev)
            if j-1>=0:
                dfs(pa,i,j-1,prev)
        
        for i in range(m):
            dfs(0, i, 0, -1)
            dfs(1, i, n-1, -1)
        
        
        for j in range(n):
            dfs(0, 0, j, -1)
            dfs(1, m-1, j, -1)
            
        res = []
        for i in range(m):
            for j in range(n):
                if dp[0][i][j] and dp[1][i][j]:
                    res.append([i,j])
        return res        