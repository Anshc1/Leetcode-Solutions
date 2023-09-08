class Solution {
public:
    int n ;
    bool check(int sum , vector<int>&a , int k ){
        int ct =0 ;
        int curr = 0 ; 
        int last = -1; 
        for(int i =0 ;i < n ; ){
            if(a[i] > sum ){
                return 0 ; 
            }
            if(curr + a[i] > sum){
                ct++; 
                curr = 0 ; 
            }
            curr+= a[i];
            i++; 
        }
        if(curr != 0 && curr <= sum ){
            ct++; 
        }
        return ct<= k; 
    }
    int splitArray(vector<int>& a, int k) {
        n = a.size(); 
        int mid , l, r ; 
        l = 0 , r = 1e9+1;
        while(l < r){
            mid =(l+r)/2; 
            if(check(mid , a, k)){
                r = mid; 
            }else{
                l = mid+1; 
            }
        }
        return r;  
    }
};