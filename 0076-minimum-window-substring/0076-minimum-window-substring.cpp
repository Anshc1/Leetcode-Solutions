class Solution {
public:
    bool check(unordered_map<char,int>&x ,unordered_map<char,int>&y){
        for(int i = 0; i < 26 ; i++){
            if(x[(char)(i+'a')] < y[(char)(i+'a')]){
                return 0 ; 
            }
            if(x[(char)(i+'A')] < y[(char)(i+'A')]){
                return 0 ; 
            }
        }
        return 1 ; 
    }
    string minWindow(string s, string t) {
        int n = s.size(); 
        unordered_map<char,int>x , y ; 
        for(auto i : t){
            y[i]++; 
        }
        int ans = 1e9 ;
        int l , r ; 
        int j = 0 ; 
        for(int i = 0; i < n ; i++){
            int rr = -1; 
            
            if(check(x , y)){
                if(rr == -1){
                    rr = j-1; 
                }
            }else{
                while(j < n ){
                x[s[j]]++; 
                if(check(x , y)){
                    rr = j ;
                    j++; 
                    break; 
                }
                j++; 
                }
            }
            //cout<< i << " " << rr << endl; 
            if(rr != -1 && rr - i+1 < ans){
                ans = rr - i +1; 
                l = i ; 
                r = rr; 
            }
            x[s[i]]-- ; 
        }
        if(ans == 1e9){
            return ""; 
        } 
        return s.substr(l , r - l+1); 
    }
};