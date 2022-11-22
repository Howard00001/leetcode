class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1,false);
        unordered_set<string> wordSet(wordDict.begin(),wordDict.end());
        dp[0]=true;
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=i;j++){
                if(!dp[j-1] || j-i>=20) continue;
                string sub = s.substr(j-1,i-j+1);
                if(wordSet.count(sub)){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};