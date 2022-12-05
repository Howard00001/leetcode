class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        maxp = nums[0]
        minp = nums[0]
        res = nums[0]
        for i in range(1,len(nums)):
            if nums[i]==0:
                maxp=minp=1
                res = max(res, 0)
            else:
                if nums[i] < 0:
                    maxp,minp=minp,maxp
                maxp = max(nums[i], maxp*nums[i])
                minp = min(nums[i], minp*nums[i])
                res = max(res, maxp)
        return res