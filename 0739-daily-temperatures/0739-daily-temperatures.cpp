class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> store, res(temperatures.size());
        for(int i=0;i<temperatures.size();i++){
            while(!store.empty() && temperatures[store.back()] < temperatures[i]){
                res[store.back()] = i - store.back();
                store.pop_back();
            }
            store.push_back(i);
        }
        while(!store.empty()){
            res[store.back()] = 0;
            store.pop_back();
        }
        return res;
    }
};