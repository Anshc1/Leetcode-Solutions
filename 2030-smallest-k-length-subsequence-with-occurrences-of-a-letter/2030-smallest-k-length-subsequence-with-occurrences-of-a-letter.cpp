class Solution {
public:
    int n ; 
    
    bool check(string&t ,string&s , int k , char l , int rep , int ct  ,int idx , vector<int>&suff){
        if(t.back() <= s[idx]){
            return 0 ; 
        }
        if(t.back() == l ){
            ct--; 
        }
        if(ct + suff[idx] < rep){ 
            return 0 ; 
        }
        if((t.size() + n - idx-1) < k ){
            return  0 ; 
        }
        return 1; 
    }
    string smallestSubsequence(string s, int k, char l, int rep) {
        n = s.size(); 
        string t = ""; 
        int ct = 0 ;
        vector<int>suff(n+1 , 0 ); 
        for(int i = n-1 ; i >= 0 ; i--){
            suff[i] = suff[i+1] + (s[i]==l);
        }
        
        for(int i = 0; i <  n ; i++){
            
            while(!t.empty()&&check(t , s , k , l , rep , ct , i , suff)){
                if(t.back() == l ){
                    ct--; 
                }
                t.pop_back(); 
            }
            if(t.size() == k ){
                continue; 
            }
            t+= s[i]; 
            if(s[i] == l){
                ct++; 
            }
        }
        cout<< t<<endl; 
        int f = 0; 
        while(ct < rep){
            ct++; 
            if(t.back() == l ){
                ct--; 
            }
            t.pop_back();
            f++; 
        }
        while(f--){
            t+= l; 
        }
        
        return t ; 
    }
};