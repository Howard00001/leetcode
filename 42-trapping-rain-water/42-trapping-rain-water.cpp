class Solution {
public:
    int trap(vector<int>& height) {
        //DP
        // int dp[height.size()], currmax=-1, res=0;
        // for(int i=0;i<height.size();i++){
        //     currmax = max(currmax, height[i]);
        //     dp[i] = currmax - height[i];
        // }
        // currmax = -1;
        // for(int i=height.size()-1;i>-1;i--){
        //     currmax = max(currmax, height[i]);
        //     res += min(currmax-height[i], dp[i]); 
        // }
        
        //2-pt
        int l=0,r=height.size()-1,res=0;
        int maxL=-1, maxR=-1;
        while(l<r){
            if(height[l]<height[r]){
                maxL = max(height[l], maxL);
                res += maxL-height[l];
                l++;
            }
            else{
                maxR = max(height[r], maxR);
                res += maxR-height[r];
                r--;
            }
        }
        return res;
    }
};