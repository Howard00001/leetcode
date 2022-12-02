class LRUCache {
public:
    list<pair<int,int>> L;
    unordered_map<int, list<pair<int,int>>::iterator> M;
    int sz;
    
    LRUCache(int capacity) {
        sz = capacity;
    }
    
    int get(int key) {
        if(!M.count(key)) return -1;
        L.splice(L.begin(), L, M[key]);
        return M[key]->second;
    }
    
    void put(int key, int value) {
        if(M.count(key)){
            L.splice(L.begin(),L, M[key]);
            M[key]->second = value;
            return;
        }
        if(M.size()==sz){
            int last_key = L.back().first;
            L.pop_back();
            M.erase(last_key);
        }
        L.push_front({key, value});
        M[key] = L.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */