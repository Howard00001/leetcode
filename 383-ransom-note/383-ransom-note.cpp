class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> m;
        for(int i=0;i<magazine.size();i++){
            if(m.count(magazine[i])){
                m[magazine[i]] += 1;
            }else{
                m[magazine[i]] = 1;
            }
        }
        for(int i=0;i<ransomNote.size();i++){
            if(!m.count(ransomNote[i])){
                return false;
            }
            if(m[ransomNote[i]]==0){
                return false;
            }
            m[ransomNote[i]]--;
        }
        return true;
    }
};