class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        for(auto str:strs){
            string tmp = str;
            sort(tmp.begin(),tmp.end());
            m[tmp].push_back(str);
        }
        for(auto vec:m){
            res.push_back(vec.second);
        }
        return res;
    }
};