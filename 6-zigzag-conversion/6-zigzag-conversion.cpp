class Solution {
public:
    string convert(string s, int numRows) {
        if(s.size()==0) return "";
        string res;
        vector<string> rows(numRows,"");
        int round, pos, oneiter=2*numRows-2;
        if(oneiter==0) return s;
        for(int i=0;i<s.size();i++){
            pos = i%oneiter;
            if(pos<numRows){
                rows[pos] += s[i]; 
            }else{
                rows[oneiter-pos] += s[i];
            }
        }
        for(int i=0;i<numRows;i++){
            res += rows[i];
        }
        return res;
    }
};