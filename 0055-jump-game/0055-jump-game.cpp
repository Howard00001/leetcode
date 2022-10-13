class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxreach=0;
        for(int i=0;i<nums.size()-1;i++){
            maxreach = max(maxreach, nums[i]+i);
            if(maxreach < i+1) break;
        }
        return maxreach >= nums.size()-1;
    }
};