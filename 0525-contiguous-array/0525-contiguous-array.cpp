class Solution {
public:
    int findMaxLength(vector<int>& a) {
        int n = a.size(); 
        vector<int>pref(n+1 , 0 ); 
        unordered_map<int,int>idx; 
        int ans = 0; 
        for(int i = 0 ; i< n ; i++){
            pref[i+1] = pref[i] + (a[i] == 1 ? 1 : -1);
            if(pref[i+1] == 0 ){
                ans = i+1; 
            }
            idx[pref[i+1]] = i+1 ; 
        }
        if(pref[n] == 0 ){
            return n ; 
        }
        for(int i = 0 ; i < n ; i++){
            ans = max(ans , idx[pref[i+1]] - i-1 ); 
        }
        return ans; 
    }
};