class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size()<p.size()) return {};
        vector<int> res;
        vector<int> sh(26,0);
        vector<int> ph(26,0);
        
        int win = p.size(), L=0,R=0;
        while(R<win){
            sh[s[R]-'a']++;
            ph[p[R]-'a']++;
            R++;
        }
        
        do{
            if(sh==ph) res.push_back(L);
            sh[s[L++]-'a']--;
            if(R>=s.size()) break;
            sh[s[R++]-'a']++;
        }while(1);
        
        return res;
    }
};