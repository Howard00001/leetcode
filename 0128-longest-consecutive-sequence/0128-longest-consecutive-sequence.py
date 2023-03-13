class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums = set(nums)
        best = 0
        for n in nums:
            if n-1 not in nums:
                y = n+1
                while y in nums:
                    y += 1
                best = max(y-n, best)
        return best