class Solution {
public:
    long long countInterestingSubarrays(vector<int>& a, int m, int k) {
        int n = a.size(); 
        int last = 0 ; 
        long long ans = 0;
        map<int,int>ct ; 
        ct[0]++; 
        int curr = 0; 
        for(int i = 0; i < n ; i++){
            curr += a[i]%m == k ? 1: 0 ;
            curr%= m ; 
            ans+= ct[(curr - k + m)%m];
            ct[curr]++; 
        }
        return ans; 
    }
};