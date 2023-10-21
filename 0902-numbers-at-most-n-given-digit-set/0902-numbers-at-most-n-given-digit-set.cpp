class Solution {
public:
    int sz ; 
    int n ; 
    string s ; 
    int dp[11][2][2] ; 
    int recur(int i , vector<string>&a , bool isLeading , bool large , string t){
        //cout<< i << endl; 
        if(i == sz){
            if(isLeading){
                reverse(t.begin() , t.end()); 
                //cout<< t<<endl; 
                return 1  ; 
            }
            return 0 ; 
        }
        if(dp[i][isLeading][large]!=-1){
            return dp[i][isLeading][large] ; 
        }
        int res = 0 ;
        if(isLeading){
            res+= recur(i+1 , a , 1 , large , t); 
        }else{
            if(i == sz-1){
                for(int j = 0 ; j < a.size() ; j++){
                    if(large){
                        if(a[j][0] < s[i]){
                            //cout << a[j][0] << " " << s[i] << endl; 
                            res+= recur(i+1 , a , 1 , s[i] >= a[j][0], t  );
                        }
                    }else{
                        if(a[j][0] <= s[i]){
                            res+= recur(i+1 , a , 1 , s[i] >= a[j][0] , t);
                        }
                    }
                }
            }else{
                for(int j = 0 ; j < a.size() ; j++){
                    if(large){
                        res+= recur(i+1 , a , 0 , s[i] <= a[j][0] , t );
                    }else{
                        res+= recur(i+1 , a , 0 , s[i] < a[j][0] , t );
                    }
                    
                    res+= recur(i+1 , a , 1 , 0 , t );
                }
            }
        }
        return dp[i][isLeading][large]  = res ; 
    }
    int atMostNGivenDigitSet(vector<string>& digits, int m) {
        s = to_string(m); 
        sz = s.size(); 
        n = m ;  
        reverse(s.begin() , s.end()); 
        //cout<< s<<endl; 
        memset(dp , -1 , sizeof(dp)); 
        return recur(0 , digits , 0 , 0 , "" ); 
    }
};