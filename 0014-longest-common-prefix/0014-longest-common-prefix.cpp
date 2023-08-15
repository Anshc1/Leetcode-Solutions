class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        int n = s.size(); 
        string t =""; 
        for(int i = 0 ; i < 300 ; i++ ){
            for(int j = 0; j< n ; j++){
                if(i >= s[j].size() || s[0][i] != s[j][i]){
                    return t ; 
                }
            }
            t+= s[0][i]; 
        }
        return t; 
    }
};