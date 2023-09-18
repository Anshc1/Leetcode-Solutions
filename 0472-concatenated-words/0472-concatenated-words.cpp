class Solution {
public:
    
    bool check(string& s , int n , set<string>&t , int i , int j , vector<vector<int>>&dp){
        if(j == n-1){
            if(i== 0 ){
                return 0 ; 
            }
            string k = s.substr(i , j - i +1 ); 
            if(t.find(k)!=t.end()){
                return 1; 
            }
            return  0 ; 
        }
        if(dp[i][j] != -1){
            return dp[i][j]; 
        }
        string k = s.substr(i , j - i+1 ); 
        int res =0 ; 
        if(t.find(k)!= t.end()){
            res|= check(s , n , t , j+1 , j+1 , dp);   
        }
        res|= check(s , n , t , i , j+1 , dp);
        return dp[i][j] = res ;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        set<string>t ;
        for(auto i : words){
            t.insert(i); 
        }
        vector<string>ans ; 
        for(auto i : words){
            int n = i.size(); 
            vector<vector<int>>dp(n, vector<int>(n, -1));
            if(check(i , n , t , 0 , 0 ,dp)){
                ans.push_back(i); 
            }
        }
        return ans; 
    }
};