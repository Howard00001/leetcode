class Solution {
public:
    int search(vector<int>& nums, int target) {
        int sz = nums.size();
        int l=0, r=sz-1, mid;
        if(!sz) return -1;
        while(l<=r){
            mid = (l+r)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]>=nums[l]){
                if(nums[mid]>=target && target>=nums[l]) r=mid-1;
                else l=mid+1;
            }else{
                if(nums[r]>=target && target>=nums[mid]) l=mid+1;
                else r=mid-1;
            }
        }
        return -1;
    }
};