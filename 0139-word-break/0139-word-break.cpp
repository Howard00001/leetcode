class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n+1,0);
        dp[n] = 1;
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        for(int i=n-1;i>=0;i--){
            string candidate = "";
            for(int j=i;j<n;j++){
                candidate += s[j];
                if(candidate.size()>25) break; // maximun leangth of word in dict is 20
                dp[i] = dp[i] || (dp[j+1] && dict.count(candidate));
                if(dp[i]) break;
            }
        }
        return dp[0];
    }
};