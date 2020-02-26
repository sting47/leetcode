class LRUCache {
private:
    map<int, int> cache;
    vector<int> lru;
    int cap;
    int curCap;
public:
    LRUCache(int capacity) {
        cap = capacity;
        curCap = 0;
    }
    
    int get(int key) {
        map<int, int>::iterator iter;
        iter = cache.find(key);
        if( iter != cache.end() ) {
            vector<int>::iterator iter_lru = find( lru.begin(), lru.end(), key );
            lru.erase(iter_lru);
            lru.push_back(key);
            return (*iter).second;
        }
        else
            return -1;
    }
    
    void put(int key, int value) {
        map<int, int>::iterator iter;
        // find if exist
        iter = cache.find(key);
        if( iter != cache.end() ) {
            vector<int>::iterator iter_lru = find( lru.begin(), lru.end(), key );
            lru.erase(iter_lru);
            lru.push_back(key);
            cache[key] = value;
        }
        else {
            if( curCap == cap ) {
                // map full
                int rmKey = lru[0];
                lru.erase(lru.begin());
                iter = cache.find(rmKey);
                cache.erase(iter);
                curCap--;
            }
            cache.insert( pair<int, int>(key, value) );
            lru.push_back(key);
            curCap++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
