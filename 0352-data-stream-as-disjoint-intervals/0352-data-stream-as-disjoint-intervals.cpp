class SummaryRanges {
public:
    vector<int>vis;  
    set<int>start ; 
    map<int,int>last; 
    SummaryRanges() {
       vis.assign(1e4+1 , 0 ); 
        last.clear(); 
    }
    
    
    void addNum(int value) {
        if(vis[value]){
            return ; 
        }
        vis[value] = 1; 
        auto it = start.upper_bound(value);
        int r = 1e6; 
        if(it!= start.end()){
            r = *it; 
        }
        int l = -4 , st =-4 ;
        if(it!= start.begin()){
            *it--;
            if(*it < value){
                l = last[*it] ; 
                st = *it ;
            }
        }
        //cout<< l << " " << r<<endl; 
        if(l == value-1 && r == value+1){
            last[st] = last[r]; 
            last.erase(r); 
            start.erase(r);
            
        }else if(l == value-1){
            last[st] = value; 
        }else if(r == value+1){
            last[value] = last[r]; 
            last.erase(r);
            start.erase(r);
            start.insert(value); 
        }else{             
            start.insert(value); 
            last[value] = value; 
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>ans; 
        for(auto i : start){
            ans.push_back({i , last[i]}); 
        }
        return ans; 
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */