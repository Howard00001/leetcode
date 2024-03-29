class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int mid, l=0, r=nums.size();
        while(l<r){
            mid = (l+r)/2;
            if(nums[mid]<target){
                l=mid+1;
            }else{
                r=mid;
            }
        }
        return l;
    }
};