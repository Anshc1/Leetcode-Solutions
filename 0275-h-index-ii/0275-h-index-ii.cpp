class Solution {
public:
    int hIndex(vector<int>& a) {
        int n = a.size(); 
        int l = 0 , r = n; 
        while(l  < r){
            int mid = (l+r)/2 ; 
            if(a[mid] >= n - mid){
                r = mid; 
            }else{
                l = mid+1 ;
            }
        }
        return n - r ; 
    }
};