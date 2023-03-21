class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n1=s.size()-1, n2=t.size()-1, back;
        while(true){
            back=0;
            while(n1>=0 && (back||s[n1]=='#')){
                back += s[n1]=='#'?1:-1;
                n1--;
            }
            back=0;
            while(n2>=0 && (back||t[n2]=='#')){
                back += t[n2]=='#'?1:-1;
                n2--;
            }
            if(n1>=0 && n2>=0 && s[n1]==t[n2]){
                n1--;
                n2--;
            }
            else
                break;
        }
        return n1==-1 && n2==-1;
    }
};