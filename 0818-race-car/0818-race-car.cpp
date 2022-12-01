class Solution {
public:
    int racecar(int target) {
        int dp[target+1];
        dp[0]=0;
        
        int n=1;
        for(int t=1;t<=target;t++){
            // int n = floor(log2(t)) + 1;
            if((1<<n)-1 == t){
                dp[t] = n;
                n++; //進位
            }
            else{
                dp[t] = n+1+dp[(1<<n)-1-t];
                for(int m=0;m<n-1;m++){
                    dp[t] = min(dp[t], n+m+1+dp[t-(1<<(n-1))+(1<<m)]);
                }
            }
            
        }
        return dp[target];
    }
};