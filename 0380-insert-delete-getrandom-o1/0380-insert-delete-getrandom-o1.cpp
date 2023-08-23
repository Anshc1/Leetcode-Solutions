class RandomizedSet {
public:
    unordered_map<int,int>x;
    vector<int>a ; 
    RandomizedSet() {
        x.clear(); 
        a.clear(); 
    }
    
    bool insert(int val) {
        if(x[val] == 0 ){
            x[val] = 1; 
            a.push_back(val); 
            return 1 ; 
        }else{
            return 0 ; 
        }
    }
    
    bool remove(int val) {
        if(x[val]){
            x[val] = 0;  
            return 1 ; 
        }else{
            return 0 ; 
        }
    }
    
    int getRandom() {
        int sz = a.size(); 
        int r = rand()%sz;
        while(x[a[r]] == 0){
            r = rand()%sz ; 
        }
        return a[r]; 
    }
};

