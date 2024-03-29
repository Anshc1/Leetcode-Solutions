class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size(); 
        int ans = 0; 
        for(int i = 0; i < n ; i++){
            map<int,int>x ; 
            for(int j = i; j < n ; j++){
                x[s[j]-'a']++; 
                if(x[s[j]-'a'] > 2){
                    break; 
                }
                ans = max(ans , j - i+1); 
            }
        }
        return ans ; 
    }
};