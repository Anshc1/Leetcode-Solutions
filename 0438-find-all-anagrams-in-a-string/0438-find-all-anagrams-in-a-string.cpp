class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ct[26] ; 
        memset(ct , 0 ,sizeof(ct)); 
        for(int i =0 ;i <p.size() ; i++){
            ct[p[i]-'a']++; 
        }
        int k = 0; 
        int curr[26] ;
        vector<int>ans; 
        memset(curr , 0 ,sizeof(curr)); 
        for(int i =0; i < s.size() ; i++){
            curr[s[i]-'a']++;
            while(1){
                bool bad = 0 ; 
                for(int j = 0; j < 26 ;j++){
                    if(curr[j] > ct[j]){
                        bad = 1; 
                        break; 
                    }
                }
                if(!bad){
                    break; 
                }else{
                    curr[s[k]-'a']--; 
                    k++; 
                }
            }
            bool ok = 1; 
            for(int j = 0 ;j < 26 ; j++){
                if(curr[j] != ct[j]){
                    ok  =0; 
                    break; 
                }
            }
            if(ok){
                ans.push_back(k); 
            }
        }
        return ans; 
    }
};