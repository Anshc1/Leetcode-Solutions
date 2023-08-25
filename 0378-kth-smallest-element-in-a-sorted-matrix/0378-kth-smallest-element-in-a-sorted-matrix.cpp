class Solution {
public:
    int kthSmallest(vector<vector<int>>& a, int k) {
        long long l = 0 ,r = 2e9 ; 
        int n = a.size();
        while( l < r){
            long long mid = (l+r)/2; 
            bool ok = 0 ; 
            int ct =0; 
            int p = 0 ;
            for(int i = 0 ; i < n ; i++){
                for(int j = 0; j < n ; j++){
                    if(a[i][j]+1e9 <  mid){
                       ct++;  
                    }
                    if(a[i][j]+1e9 == mid){
                        p++; 
                    }
                }
            }
            if(ct + p >= k){
                r = mid; 
            }else{
                l = mid+1 ;
            }
        }
        return r-1e9; 
    }
};