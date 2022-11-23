class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        s = sum(nums)
        if (s&1)==1:
            return False
        s = int(s/2)
        bits = 1
        for num in nums:
            bits = bits | (bits<<num)
        return bits&pow(2,s)