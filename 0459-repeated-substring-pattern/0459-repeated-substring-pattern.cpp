class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = "";
        int n = s.size(); 
        for(int i =1 ;i <= n/2 ; i++ ){
            t+= s[i-1]; 
            if(n%i == 0   ){
                string temp= ""; 
                while(temp.size() < s.size()){
                    temp+= t; 
                }
                if(temp == s){
                    return 1; 
                } 
            }
        }
        return 0 ; 
    }
};