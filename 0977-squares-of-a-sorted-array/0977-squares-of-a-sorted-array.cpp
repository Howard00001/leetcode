class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size());
        int left=0, right=nums.size()-1, curr=right;
        for(;curr>=0;curr--){
            if(abs(nums[left])<abs(nums[right])){
                res[curr] = nums[right]*nums[right];
                right--;
            }
            else{
                res[curr] = nums[left]*nums[left];
                left++;
            }
        }
        return res;
    }
};