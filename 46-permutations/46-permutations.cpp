class Solution {
public:
    void backtrack(vector<int>& nums, int curr){
        if(curr==nums.size()-1){
            res.push_back(nums);
            return;
        }
        backtrack(nums,curr+1);
        for(int i=curr+1;i<nums.size();i++){
            swap(nums[curr],nums[i]);
            backtrack(nums,curr+1);
            swap(nums[curr],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums,0);
        return res;
    }
private:
    vector<vector<int>> res;
};