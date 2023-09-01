class MedianFinder {
public:
    multiset<int>a, b ; 
    int sz = 0; 
    MedianFinder() {
        a.clear(); 
        b.clear(); 
    }
    
    void addNum(int u) {
        a.insert(u); 
        sz++;
        while( a.size() > (sz/2)){
            b.insert(*--a.end());
            a.erase(--a.end());
        }
        while(!a.empty() && *--a.end() > *b.begin()){
            int u = *--a.end();
            int v = *b.begin(); 
            a.erase(--a.end()); 
            b.erase(b.begin());
            a.insert(v);
            b.insert(u); 
        }
    }
    
    double findMedian() {
        if(sz%2 ){
            return *b.begin();
        }
        double x =  *--a.end() ; 
        double y = *b.begin(); 
        double p  = (x +y ) / 2 ; 
        return p ; 
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */