class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        int mx = 1<< 9 ;
        vector<vector<int>>ans ; 
        for(int i = 0; i < mx ; i++){
            int ct = 0; 
            int val = 0; 
            vector<int>res; 
            for(int j = 0; j < 9 ; j++){
                if((i>>j)&1){
                    ct++;
                    val+= j+1;
                    res.push_back(j+1); 
                }
            }
            if(ct == k && val == n ){
            
                //cout<< i << " " << ct << " " << val <<endl ;  
                ans.push_back(res); 
            }
        }
        return ans ; 
    }
};