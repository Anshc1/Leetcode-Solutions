class LRUCache {
public:
    map<int,int>vals; 
    int sz; 
    int cap; 
    list<int>dll; 
    map<int,list<int>::iterator>it;

    LRUCache(int capacity) {
        sz = 0;
        cap = capacity; 
    }

    void update_iterator(int key) {
        dll.erase(it[key]);
        dll.push_front(key);
        it[key] = dll.begin(); 
    }

    int get(int key) {
        if(vals.count(key) == 0) {  // Check if key exists
            return -1; 
        }
        update_iterator(key); 
        return vals[key]-1; 
    }
    
    void put(int key, int value) {
        if(vals.count(key) != 0) {  // Check if key exists
            vals[key] = value+1;
            update_iterator(key); 
            return; 
        }
        
        if(sz == cap) {
            auto lastIt = --dll.end();
            vals.erase(*lastIt);    // Remove the key from vals
            it.erase(*lastIt);      // Remove the key from it
            dll.erase(lastIt);
            sz--;
        }
        
        dll.push_front(key);
        vals[key] = value+1;
        it[key] = dll.begin();  // Update the it map
        sz++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */