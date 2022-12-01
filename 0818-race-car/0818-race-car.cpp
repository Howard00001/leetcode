class Solution {
public:
//     int racecar(int target) {
//         int n = floor(log2(target)) + 1;
//         int dp[n];
        
//         if((1<<n)-1 == target) return n;
        
//         for(int t=1;t<target;t++){
//             int tn = floor(log2(t)) + 1;
//             dp[t] = 
//         }
//         else{
//             //case 1
//             dp[target] = n+1+racecar((1<<n)-1-target);
//             //case 2
//             for(int m=0;m<n-1;m++){
//                 dp[target] = min(dp[target], n+m+1+racecar(target-(1<<(n-1))+(1<<m)));
//             }
//         }
//         return dp[target];
//     }
    int racecar(int target) {
        vector<int> dp(target+1, INT_MAX);
        int r = 1;
        for (int i = 1; i <= target; i++) {
            if (i == pow(2,r)-1) {
                dp[i] = r;
                r++;
            }
            else {
                int lower = pow(2, r-1)-1;
                int upper = pow(2, r)-1;
                for (int j = 0; j < r-1; j++) {
                    dp[i] = min(dp[i], r+1+j+dp[i-pow(2,r-1)+pow(2,j)]);
                }
                dp[i] = min(dp[i], r+1+dp[upper-i]);
            }
        }
        return dp[target];
    }
};