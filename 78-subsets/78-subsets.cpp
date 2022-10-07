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
        vector<vector<int>> ans;
        int n = nums.size();
        int num = pow(2, n), i = 0;
        
        while(i<num)
        {
            vector<int> temp;
            for(int j=0; j<n; j++)
            {
                if(i & 1<<j)
                    temp.push_back(nums[j]);
            }
            ans.push_back(temp);
            i++;
        }
        
        return ans;
    }
};