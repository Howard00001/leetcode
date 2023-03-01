class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        total = 0
        for i in range(len(nums)):
            total += nums[i]
        target = int((1+len(nums))*len(nums)/2)
        return target - total
                
        