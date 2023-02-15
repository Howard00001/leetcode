class Solution:
    def reverse(self, nums, st, ed):
        while st < ed:
            tmp = nums[st]
            nums[st] = nums[ed]
            nums[ed] = tmp
            st+=1
            ed-=1
            
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        k = k%n
        
#         self.reverse(nums,0,n-k-1)
#         self.reverse(nums,n-k,n-1)
#         self.reverse(nums,0,n-1)
        tmp = nums[n-k:n]
        tmp.extend(nums[0:n-k])
        for i in range(n):
            nums[i] = tmp[i]
        
        
            