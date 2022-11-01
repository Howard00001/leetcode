class Solution {
public:
    int countSubstrings(string s) {
        int res=s.size();
        for(int i=0;i<s.size();i++){
            int expand = 1;
            if(i-1>=0 && s[i-1] == s[i]){
                res++;
                while(expand){
                    int l = i-1-expand, r=i+expand;
                    if(l>=0 && r<s.size() && s[l]==s[r]){
                        res++;
                        expand++;
                    } 
                    else break;
                }
            } 
            expand = 1;
            while(expand){
                int l = i-expand, r=i+expand;
                if(l>=0 && r<s.size() && s[l]==s[r]){
                    res++;
                    expand++;
                } 
                else break;
            }
        }
        return res;
    }
};