class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        s = sum(nums)
        if (s&1)==1:
            return False
        s = int(s/2)
        dp = [False]*(s+1)
        dp[0] = True
        for num in nums:
            for i in range(s,-1,-1):
                if i-num >=0:
                    dp[i] = dp[i] | dp[i-num]
        return dp[s]
    
        # s = sum(nums)
        # if (s&1)==1:
        #     return False
        # s = int(s/2)
        # bits = 1
        # for num in nums:
        #     bits = bits | (bits<<num)
        # return bits&pow(2,s)