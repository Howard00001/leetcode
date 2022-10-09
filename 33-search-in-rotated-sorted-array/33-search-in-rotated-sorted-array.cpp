class Solution {
public:
    int search(vector<int>& nums, int target) {
        int sz = nums.size();
        int s, l=0, r=sz-1, mid;
        if(!sz) return -1;
        while(l<r){
            mid = (l+r)/2;
            if(nums[l]<nums[r]){
                s = l;
                break;
            }
            else if(nums[mid]>nums[r]) l = mid+1;
            else  r = mid;
        }
        l=s;
        r=s+sz;
        while(l<r){
            mid = (l+r)/2;
            if(nums[mid%sz]==target) return mid%sz;
            else if(nums[mid%sz]<target) l=mid+1;
            else r = mid;
        }
        return -1;
    }
};