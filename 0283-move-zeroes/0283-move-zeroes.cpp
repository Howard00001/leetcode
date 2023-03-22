class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeros=0, n=nums.size();
        for(int i=0;i<n;i++){
            while(i<n && nums[i]==0){
                zeros++;
                i++;
            }
            if(zeros>0 && i<n)
                swap(nums[i],nums[i-zeros]);
        }
    }
};