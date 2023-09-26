
class Solution {
public:
    bool check(int last , int curr) {
        int n = last * 10  + curr ;
        if (n >= 0 && n <= 26) {
            //cout<<last << " " << curr << " "<< n <<endl; 
            return 1;
        }
        return 0 ;
    }
    int dp[100001][10][2]; 
    int n ;
    string s; 
    int mod = 1e9+7; 
    int recur(int idx , int last , bool taken ) {
        if (idx == n) {
            if (taken) {
                return 0 ;
            }
            return 1;
        }
        if(dp[idx][last][taken] != -1){
            return dp[idx][last][taken] ;
        }
        int res = 0 ;
        if (s[idx] == '*') {
            if (taken) {
                for (int i = 1 ; i <= 9 ; i++) {
                    if (check(last , i)) {
                        res += recur(idx + 1 , 0 , 0 );
                        res%=mod; 
                    }
                }
            } else {
                for (int i = 1 ; i <= 9 ; i++) {
                    res += recur(idx + 1 , 0 , 0 );
                    res%=mod; 
                    res += recur(idx + 1 , i , 1 );
                    res%=mod; 
                }
            }
        } else {
            if (taken) {
                if (check(last , s[idx] - '0')) {
                    res += recur(idx + 1 , 0, 0 );
                    res%=mod; 
                }
            } else {
                if (s[idx] != '0') {
                    res += recur(idx + 1 , 0 , 0 );
                    res%=mod; 
                    res += recur(idx + 1 , s[idx] - '0' , 1 );
                    res%=mod; 
                }
            }
        }
        return dp[idx][last][taken] =  res ; 
    }
    int numDecodings(string t) {
        memset(dp , -1, sizeof(dp)); 
        s= t; 
        n = s.size(); 
        return recur(0 , 0 , 0 ); 
    }
};
