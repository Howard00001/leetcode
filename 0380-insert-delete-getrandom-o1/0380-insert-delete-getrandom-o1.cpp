class RandomizedSet {
public:
    vector<int> ls;
    unordered_map<int,int> id;
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(!id.count(val)){
            id[val] = ls.size();
            ls.push_back(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(!id.count(val)) return false;
        // if(id[val]!=ls.size()-1){
        id[ls[ls.size()-1]]=id[val];
        swap(ls[ls.size()-1], ls[id[val]]);
        // }
        id.erase(val);
        ls.pop_back();
        return true;
    }
    
    int getRandom() {
        return ls[rand()%ls.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */