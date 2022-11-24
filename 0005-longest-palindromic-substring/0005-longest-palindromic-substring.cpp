class Solution {
public: 
    string longestPalindrome(string s) {
        int n=s.size(), start=0, res_len=0;
        for(int i=0;i<n&&res_len+1<(n-i)*2;){
            int L=i,R=i;
            while(R+1<n && s[R]==s[R+1]) R++;
            i = R+1;
            while(L>0 && R+1<n && s[L-1] == s[R+1]){
                L--;
                R++;
            }
            int len = R-L+1;
            if(res_len<len){
                res_len = len;
                start = L;
            }
        }
        return s.substr(start,res_len);
    }
};