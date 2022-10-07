class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int first,second;
        if(nums.size()==1) return nums[0];
        first = nums[0];
        second = max(nums[0],nums[1]);
        for (int i=2;i<nums.size();i++) {
            first = max(first+nums[i], second);
            swap(first,second);
        }
        return second;
    }
};