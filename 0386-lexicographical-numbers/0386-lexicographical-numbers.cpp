class Solution {
public:
    vector<int>ans; 
    bool ok = 0; 
    void recur(int curr , int n  ){
        if(curr > n ){
            return ; 
        }else{
            ans.push_back(curr);
            for(int i = 0 ; i < 10 ; i++){
                if(curr * 10 + i > n ){
                    return ; 
                }
                recur(curr*10 + i , n ); 
            }
        }
        
    }
    vector<int> lexicalOrder(int n) {
        ans.clear();
        for(int i = 1; i <= 9 ; i++){
             recur(i , n );
        }
        return ans; 
    }
};