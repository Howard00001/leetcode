class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxA = 0;
        int L=0,R=height.size()-1;
        while(L<R){
            maxA = max(min(height[L],height[R])*(R-L), maxA);
            if(height[L]<height[R]) L++;
            else R--;
        }
        return maxA;
    }
};