class Solution {
public:
    int search(vector<int>& nums, int target) {
        int L=0,R=nums.size()-1,M;
        while(L<=R){
            M=(L+R)/2;
            if(target==nums[M]) return M;
            if(target==nums[L]) return L;
            if(target==nums[R]) return R;
            if(nums[L]<nums[M]){
                if(target < nums[M] && target > nums[L])
                    R = M-1;
                else
                    L = M+1;
            }else{
                if(target > nums[M] && target < nums[R])
                    L = M+1;
                else
                    R = M-1;
            }
        }
        return -1;
    }
};