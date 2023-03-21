class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int r=0;
        bool cont=true;
        if(strs.size()==1) return strs[0];
        
        while(cont){
            char curr = strs[0][r];
            for(int i=1;i<strs.size();i++){
                if(r>=strs[i].size() || strs[i][r]!=curr){
                    cont=false;
                    r--;
                    break;
                }
            }
            r++;
        }
        return strs[0].substr(0,r);
    }
};