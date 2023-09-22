class Solution {
public:
    int n , m ; 
    bool check(vector<int>&a , vector<int>&b , int curr){
        int idx = 0 ;  
        for(int i =0 ;i < m ; i++){
            while(idx < n && (a[idx]>= b[i]-curr) && (a[idx]<= b[i] +curr )){
                idx++; 
            }
        }
        return idx >= n ; 
    }
    int findRadius(vector<int>& a, vector<int>& b) {
        n  = a.size(); 
        m  = b.size(); 
        int l =0 , r = 2e9;
        sort(a.begin() , a.end()); 
        sort(b.begin() , b.end()); 
        while(l < r){
            int mid = (l+r)>>1; 
            if(check(a , b, mid)){
                r = mid; 
            }else{
                l  =mid+1; 
            }
        }
        return r; 
    }
};