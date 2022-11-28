class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        if(n==2) return {0,1};
        
        vector<vector<int>> next(n);
        vector<int> degree(n);
        for(auto edge:edges){
            int a=edge[0], b= edge[1];
            degree[a]++;
            degree[b]++;
            next[a].push_back(b);
            next[b].push_back(a);
        }
        
        queue<int> Q;
        for(int i=0;i<n;i++){
            if(degree[i]==1) Q.push(i);
        }
        while(n>2){
            int sz = Q.size();
            n-=sz;
            while(sz--){
                int cur=Q.front();
                Q.pop();
                for(int nx:next[cur]){
                    if(--degree[nx]==1) Q.push(nx);
                }
            }
        }
        
        vector<int> res;
        while(!Q.empty()){
            res.push_back(Q.front());
            Q.pop();
        }
        return res;
    }
};