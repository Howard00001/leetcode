// class Solution {
// public:
//     void backtrack(const vector<int>& nums, int curr, vector<int> sub){
//         if(curr==nums.size()){
//             res.push_back(sub);
//             return;
//         } 
//         backtrack(nums, curr+1, sub);
//         sub.push_back(nums[curr]);
//         backtrack(nums, curr+1, sub);
//     }
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<int> sub;
//         backtrack(nums,0,sub);
//         return res;
//     }
// private:
//     vector<vector<int>> res;
// };
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int bound = pow(2, nums.size());
        for(int i=0;i<bound;i++){
            vector<int> tmp;
            for(int j=0;j<nums.size();j++){
                if(1<<j & i) tmp.push_back(nums[j]);
            }
            res.push_back(tmp);
        }
        return res;
    }
};