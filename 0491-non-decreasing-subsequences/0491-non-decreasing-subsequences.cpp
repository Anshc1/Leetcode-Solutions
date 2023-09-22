class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& a) {
        int n = a.size(); 
        int mx = 1<<n ; 
        vector<vector<int>>ans; 
        mx--; 
        set<vector<int>>s ; 
        for(int i =1 ; i <= mx ;i++ ){
            int prev = -101;
            bool bad = 0 ; 
            int ct =0 ; 
            vector<int>x; 
            for(int j =0 ; j < n ; j++){
                if(((i>>j)&1)){
                    ct++; 
                    x.push_back(a[j]); 
                    if(prev == -101){
                        prev = a[j]; 
                    }else{
                        if(a[j] < prev){
                            bad =1; 
                            break; 
                        }
                        prev = a[j]; 
                    }
                }
            }
            if(ct >=2 && !bad){
                s.insert(x); 
            }
        }
        for(auto i : s){
            ans.push_back(i); 
        }
        return ans; 
    }
};