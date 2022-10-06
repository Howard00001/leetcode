class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int f = -1, next=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]){
                f = i;
                next = i+1;
            }
            if(f>-1 && nums[i]>nums[f] && nums[i]<nums[next]){
                next = i;
            }
        }
        int i = nums.size()-1;
        if(f>-1 && nums[i]>nums[f] && nums[i]<nums[next]){
            next = i;
        }
        if(f==-1){
            sort(nums.begin(),nums.end());
        }
        else{
            swap(nums[f],nums[next]);
            sort(nums.begin()+f+1,nums.end());
        }
        
    }
};