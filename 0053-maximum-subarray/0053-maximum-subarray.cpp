class Solution {
public:      
    int maxSubArray(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);        
        int sum = 0, smax = INT_MIN;
        for (int num : nums) {
            sum += num;
            smax = max(smax, sum);
            if (sum < 0) {
                sum = 0;
            }
        }
        return smax;
    }
};