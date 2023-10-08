class Solution {
public:
    int balancedString(string s) {
        int n = s.size(); 
        unordered_map<int,int>ct , ex ;  
        for(auto i : s){
            ct[i-'A']++; 
        }
        for(auto i : ct){
            if(i.second > n/4){
                ex[i.first] = 1; 
            }
        }
        if(ex.empty()){
            return 0 ; 
        }
        int ans= 1e9 ; 
        map<int,int>x; 
        int j = 0 ;
        vector<char> p = {'Q' , 'W' , 'E' , 'R'}; 
        for(int i = 0; i < n ;i++ ){
            x[s[i]-'A']++;
            while(j < i){
                x[s[j]-'A']--; 
                bool bad =0 ; 
                for(auto k : p){
                    if(x[k-'A'] < (ct[k-'A'] - n/4)){ 
                        bad =1; 
                        break; 
                    }
                }
                if(bad){
                    x[s[j]-'A']++; 
                    break ; 
                }
                j++; 
            }
            bool bad =0; 
            for(auto k : p){
                if(x[k-'A'] < ct[k-'A']-n/4){
                    bad =1; 
                }
            }
            //cout<< i << " " << bad << endl; 
            if(!bad){
                ans = min(ans, i - j+1) ; 
            }
        }
        return ans; 
    }
};