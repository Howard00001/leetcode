class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> M;
        int maxres = 0, cum = 0;
        M[0] = -1;
        for(int i=0;i<nums.size();i++){
            int curr = (nums[i]==1)?1:-1;
            cum += curr;
            if(!M.count(cum))
                M[cum] = i;
            else
                maxres = max(maxres,i-M[cum]);
        }
        return maxres;
    }
};