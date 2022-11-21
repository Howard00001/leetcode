class Solution {
public:
    unordered_map<string, string> parent;
    unordered_map<string, string> owner;
    unordered_map<string, set<string>> group;
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // 1. initial
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                parent[accounts[i][j]] = accounts[i][j];
                owner[accounts[i][j]] = accounts[i][0];
            }
        }
        // 2. Union
        for(int i=0;i<accounts.size();i++){
            for(int j=2;j<accounts[i].size();j++){
                if(FindSet(accounts[i][j])!=FindSet(accounts[i][j-1]))
                    Union(accounts[i][j], accounts[i][j-1]);
            }
        }
        // 3. Create Set
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                string p = FindSet(accounts[i][j]);
                group[p].insert(accounts[i][j]);
            }
        }
        // 4. Generate result
        vector<vector<string>> res;
        for(auto g:group){
            vector<string> tmp;
            tmp.push_back(owner[g.first]);
            for(auto &s:g.second){
                tmp.push_back(s);
            }
            res.push_back(tmp);
        }
        return res;
    }
    
    string FindSet(string x){
        if(x!=parent[x])
            parent[x] = FindSet(parent[x]);
        return parent[x];
    }
    
    void Union(string x, string y){
        x = parent[x];
        y = parent[y];
        if(x>y) parent[x] = y;
        else parent[y] = x;
    }
};