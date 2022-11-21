class DSU {
    vector<int> rank, parent, size;
public:
    DSU(int n){
        rank.resize(n,0);
        parent.resize(n);
        size.resize(n,1);
        for(int i = 0;i<n;i++) {
            parent[i] = i; 
            //size[i] = 1; 
        }
        //iota(parent.begin(),parent.end(),0);
    }
    int find(int x){
        if(x==parent[x]) return x;
        return parent[x]=find(parent[x]);
    }
    void unionByRank(int x, int y){
        x = find(x);
        y = find(y);
        if(x==y) return;
        if(rank[x]<rank[y]) parent[x] = y;
        else if(rank[y]<rank[x]) parent[y] = x;
        else{
            parent[y]=x;
            rank[x]++;
        }
    }
    void unionBySize(int x, int y){
        x = find(x);
        y = find(y);
        if(size[x] < size[y]){
            parent[x] = y;
            size[y] += size[x];
        } 
        else{
            parent[y] = x;
            size[x] += size[y];
        }
    }
};
////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        DSU dsu(accounts.size());
        unordered_map<string, int> m;
        // 1
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                string s = accounts[i][j];
                if(m.count(s)) dsu.unionByRank(i, m[s]);
                else m[s] = i;
            }
        }
        // 2
        vector<vector<string>> sets(accounts.size());
        for(auto it:m){
            string mail=it.first;
            int root = dsu.find(it.second);
            sets[root].push_back(mail);
        }
        // 3
        vector<vector<string>> res;
        for(int i=0;i<accounts.size();i++){
            if(sets[i].size()==0) continue;
            sort(sets[i].begin(),sets[i].end());
            vector<string> tmp;
            tmp.push_back(accounts[i][0]);
            for(auto it:sets[i]){
                tmp.push_back(it);
            }
            res.push_back(tmp);
        }
        return res;
    }
};