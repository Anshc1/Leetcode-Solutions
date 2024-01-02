class DataStream {
public:
    int ct ; 
    int v ; 
    int kk ; 
    DataStream(int value, int k) {
        ct = 0;
        v = value ; 
        kk = k ;
    }
    
    bool consec(int num) {
        if(num == v ){
            ct++; 
        }else{
            ct =0 ; 
        }
        return ct >= kk ; 
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */