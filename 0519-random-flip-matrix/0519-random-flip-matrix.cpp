class Solution {
public:
    map<pair<int,int> , int >x; 
    int mm , nn ; 
    Solution(int m, int n) {
        x.clear();
        mm = m ; 
        nn = n ; 
    }
    
    vector<int> flip() {
        int i = rand()%mm ; 
        int j = rand()%nn ;
        while(x[{i, j }]){
            i = rand()%mm ; 
            j = rand()%nn ;
        }
        x[{i, j}] = 1 ; 
        vector<int>a = { i , j }; 
        return a ; 
    }
    
    void reset() {
        x.clear(); 
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */