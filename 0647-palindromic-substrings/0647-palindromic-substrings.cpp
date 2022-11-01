class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(),false));
        int res = s.size();
        for(int i=0;i<s.size()-1;i++){
            dp[i][i] = true;
            if(s[i] == s[i+1]){
                dp[i][i+1] = true;
                res++;
            } 
        }
        dp[s.size()-1][s.size()-1] = true;
        for(int i=0;i<s.size();i++){
            for(int j=i-2; j>=0;j--){
                if(dp[j+1][i-1]==true && s[j]==s[i]){
                    res++;
                    dp[j][i] = true;
                }
            }
        }
        return res;
    }
};