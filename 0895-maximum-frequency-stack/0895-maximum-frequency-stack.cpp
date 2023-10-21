class FreqStack {
public:
    unordered_map<int,int>ct ; 
    set<pair<pair<int,int>, int>>x ; 
    int tm ; 
    FreqStack() {
        tm = 0; 
        ct.clear(); 
        x.clear(); 
    }
    
    void push(int val) {
        ct[val]++; 
        x.insert({{ct[val] ,tm } , val}); 
        tm++; 
    }
    int pop() {
        auto it = *--x.end(); 
        ct[it.second]--; 
        x.erase(--x.end()); 
        return it.second ; 
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */