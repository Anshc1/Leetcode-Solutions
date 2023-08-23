class Solution {
public:
    vector<int>a , curr;
    int n ; 
    Solution(vector<int>& b) { 
        a = b;
        n = b.size(); 
        curr = b; 
    }
    
    vector<int> reset() { 
        return curr; 
    }
    
    vector<int> shuffle() {
        vector<int>x(n , -1); 
        int j = 0; 
        while(j < n ){
            int r = rand(); 
            r%= n ; 
            if(x[r] == -1){
                x[r] = curr[j]; 
                j++; 
            }
        }
        return x; 
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */