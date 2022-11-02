class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int sel = costs.size()/2;
        sort(costs.begin(), costs.end(), cmp);
        int res = 0;
        for(int i=0;i<costs.size();i++){
            if(i<sel) res+=costs[i][0];
            else res+=costs[i][1];
        }
        
        return res;
    }
    static bool cmp(vector<int>& v1, vector<int>& v2){
        return v1[1]-v1[0] > v2[1]-v2[0];
    }
};