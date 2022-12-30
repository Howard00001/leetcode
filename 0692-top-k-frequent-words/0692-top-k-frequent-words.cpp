class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> M;
        vector<string> unique_w;
        vector<int> count;
        
        for(auto s:words){
            if(!M.count(s)){
                M[s] = count.size();
                count.push_back(1);
                unique_w.push_back(s);
            }
            else{
                count[M[s]]++;
            }
        }
        
        vector<int> indices(count.size());
        iota(indices.begin(),indices.end(), 0);
        sort(indices.begin(),indices.end(), 
             [&count, &unique_w](int a, int b){
                 if(count[a]==count[b]) return unique_w[a] < unique_w[b];
                 return count[a] > count[b];
             });
        
        vector<string> res;
        for(int i=0;i<k;i++){
            res.push_back(unique_w[indices[i]]);
        }
        return res;
        // itoa
        // for(int i=0;i<indices.size();i++)
        //     indices[i] = i;
        
        
    }
};