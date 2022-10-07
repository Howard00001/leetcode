class Solution {
public:
    void backtrack(const vector<int>& nums, int curr, vector<int> sub){
        if(curr==nums.size()){
            res.push_back(sub);
            return;
        } 
        backtrack(nums, curr+1, sub);
        sub.push_back(nums[curr]);
        backtrack(nums, curr+1, sub);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> sub;
        backtrack(nums,0,sub);
        return res;
    }
private:
    vector<vector<int>> res;
};