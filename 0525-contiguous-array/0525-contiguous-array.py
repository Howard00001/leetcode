class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        record = {}
        s = 0
        res = 0
        
        record[0] = -1
        for i in range(len(nums)):
            if nums[i]==1:
                curr = 1
            else:
                curr = -1
                
            s += curr
            
            if s not in record:
                record[s] = i
            else:
                res = max(res, i-record[s])
        
        return res