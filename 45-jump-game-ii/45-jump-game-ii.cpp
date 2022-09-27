class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int maxReach=0, lastpos=0;
        int jump=0;
        int i=0;
        while(lastpos<n-1){
            maxReach = max(maxReach, i+nums[i]);
            if(i==lastpos){
                lastpos=maxReach;
                jump++;
            }
            i++;
        }
        return jump;
    }
};