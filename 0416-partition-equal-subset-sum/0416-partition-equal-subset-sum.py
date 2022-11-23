class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        
        # dp 2D
        s = sum(nums)
        n = len(nums)
        if (s&1)==1:
            return False
        s = int(s/2)
        dp = [([False]*(s+1)) for i in range(n+1)]
        for i in range(n+1):
            dp[i][0] = True
        for j in range(s+1):
            dp[0][j] =False
        for i in range(1,n+1):
            for j in range(1,s+1):
                dp[i][j] = dp[i-1][j]
                if j-nums[i-1]>=0:
                    dp[i][j] = dp[i][j] | dp[i-1][j-nums[i-1]]
        return dp[len(nums)][s]
        
        # space optimize
        # s = sum(nums)
        # if (s&1)==1:
        #     return False
        # s = int(s/2)
        # dp = [False]*(s+1)
        # dp[0] = True
        # for num in nums:
        #     for i in range(s,-1,-1):
        #         if i-num >=0:
        #             dp[i] = dp[i] | dp[i-num]
        # return dp[s]
    
        # bit operation
        # s = sum(nums)
        # if (s&1)==1:
        #     return False
        # s = int(s/2)
        # bits = 1
        # for num in nums:
        #     bits = bits | (bits<<num)
        # return bits&pow(2,s)