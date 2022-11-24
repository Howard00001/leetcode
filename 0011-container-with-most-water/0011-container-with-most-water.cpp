class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxA = 0;
        int L=0,R=height.size()-1;
        while(L<R){
            int curr = min(height[L],height[R])*(R-L);
            if(curr>maxA) maxA= curr;
            if(height[L]<height[R]) L++;
            else R--;
        }
        return maxA;
    }
};