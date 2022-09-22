class Solution {
void backtrack(const vector<int>& candidates, int target, vector<int>& comb, int sum, int curr) {
    if(sum > target) return;
    if(sum == target){
        res.push_back(comb);
        return;
    }
    for(int i=curr;i<candidates.size();i++){
        sum += candidates[i];
        comb.push_back(candidates[i]);
        backtrack(candidates, target, comb, sum, i);
        comb.pop_back();
        sum -= candidates[i];
    }
}
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> comb;
        backtrack(candidates, target, comb, 0, 0);
        return res;
    }
private:
    vector<vector<int>> res;
};