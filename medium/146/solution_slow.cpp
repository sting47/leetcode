class LRUCache {
private:
    vector< vector<int> > cache;
    int cap;
public:
    LRUCache(int capacity) {
        int i = 0;
        vector<int> key(capacity);
        vector<int> value(capacity);
        vector<int> cnt(capacity);
        cap = capacity;
        // reserve for key, value, ref freq
        cache.push_back(key);
        cache.push_back(value);
        cache.push_back(cnt);
        for( i=0; i<capacity; i++ ) {
            // means not used
            cache[2][i] = -1;
        }
    }
    
    int get(int key) {
        int i = 0;
        for( i=0; i<cap; i++ ) {
            if( cache[0][i] == key && cache[2][i] != -1 ) {
                // increase all other element ref freq
                int j = 0;
                for( j=0; j<cap; j++ ) {
                    if( j == i ) {
                        cache[2][j] = 0;
                    }
                    else if( cache[2][j] == -1 ) {
                        continue;
                    }
                    else {
                        cache[2][j]++;
                    }
                }
                return cache[1][i];
            }
        }
        return -1;
    }
    
    void put(int key, int value) {
        int i = 0;
        // find if already exist
        for( i=0; i<cap; i++ ) {
            if( cache[0][i] == key && cache[2][i] != -1 ) {
                // increase all other element ref freq
                int j = 0;
                for( j=0; j<cap; j++ ) {
                    if( j == i ) {
                        cache[2][j] = 0;
                    }
                    else if( cache[2][j] == -1 ) {
                        continue;
                    }
                    else {
                        cache[2][j]++;
                    }
                }
                cache[1][i] = value;
                return;
            }
        }
        for( i=0; i<cap; i++ ) {
            if( cache[2][i] == -1 ) {
                // empty slot
                cache[0][i] = key;
                cache[1][i] = value;
                cache[2][i] = 0;
                return;
            }
        }
        // invalidate the least recently used
        i = distance( cache[2].begin(), max_element( cache[2].begin(), cache[2].end() ) );
        cache[0][i] = key;
        cache[1][i] = value;
        cache[2][i] = 0;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
