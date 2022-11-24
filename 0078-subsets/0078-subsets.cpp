class Solution {
public:
    vector<vector<int>> res;
    
    void dfs(int curr, vector<int> tmp, vector<int>& nums){
        if(curr==nums.size()){
            res.push_back(tmp);
            return;
        }
        dfs(curr+1, tmp, nums);
        tmp.push_back(nums[curr]);
        dfs(curr+1, tmp, nums);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> tmp;
        dfs(0, tmp, nums);
        return res;
    }
};