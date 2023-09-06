class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = "";
        int n = s.size();
        vector<int>lps(n+1 , 0) ;
        int len = 0 ;
        for(int i = 1 ; i < n ; ){
            if(s[i] == s[len]){
                len++; 
                lps[i] = len ; 
                i++; 
            }else {
                if(len != 0 ){
                    len = lps[len-1]; 
                }else{ 
                    lps[i]= 0 ; 
                    i++ ;
                }
            }
        }
        if( n % (n - lps[n-1]) == 0 && lps[n-1] >  0  ){
            return 1; 
        }
        return 0 ; 
    }
};