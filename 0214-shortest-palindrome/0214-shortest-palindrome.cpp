class Solution {
public:
    string shortestPalindrome(string s) {
        string t =s; 
        string f =s; 
        s+= '#';
        reverse(t.begin() , t.end()); 
        s+= t; 
        vector<int>p(s.size() , 0 );
        int len = 0 ; 
        for(int i =1 ;i < s.size() ; ){ 
            if(s[i] == s[len]){
                len++; 
                p[i] = len; 
                i++; 
            }else{
                if(len > 0 ){
                    len = p[len -1]; 
                }else{
                    i++; 
                }
            }
        }
        int n = f.size(); 
        int mx =  p[s.size()-1];
        string ans ="" ;
        for(int i = n-1 ; i>= mx ; i--){
            ans+= f[i]; 
        }
        ans+= f; 
        return ans;
        
    }
};