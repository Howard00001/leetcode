class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> S;
        for(auto n:nums){
            if(S.count(n)) return true;
            S.insert(n);
        }
        return false;
    }
};