class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0 && nums[i]<=nums.size() && nums[i]!=nums[nums[i]-1])
            {
                swap(nums[i],nums[nums[i]-1]);
                i--;
            }
        }
        int ans=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=i+1)
            {
                ans=i+1;
                break;
            }
        }
        if(ans==-1)
        {
            ans=nums.size()+1;
        }
        return ans;
    }
};