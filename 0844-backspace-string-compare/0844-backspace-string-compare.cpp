class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string sn="", tn="";
        for(auto c:s){
            if(c=='#'){
                if(!sn.empty())
                    sn.pop_back();
            }
            else
                sn.push_back(c);
        }
        for(auto c:t){
            if(c=='#'){
                if(!tn.empty())
                    tn.pop_back();
            }
            else
                tn.push_back(c);
        }
        return sn==tn;
    }
};