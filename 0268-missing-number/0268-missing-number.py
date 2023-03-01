class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        #return int((1+len(nums))*len(nums)/2) - sum(nums)
    
        res = n = len(nums)
        for i in range(n):
            res ^= nums[i]^i
        return res