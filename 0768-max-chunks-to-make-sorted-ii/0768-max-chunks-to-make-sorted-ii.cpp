class Solution {
public:
    int find_seg(int l , int  r , vector<int>&a){  
        unordered_map<int,int>x; 
        int mn = 1e9 ; 
        for(int i =r  ; i >= l  ; i-- ){
            mn = min(mn , a[i]); 
            x[i] = mn; 
        }
        int mx = 0 ; 
        int ans =1 ; 
        for(int i = l  ;i <  r ; i++){
            mx = max(mx , a[i]); 
            if(mx <= x[i+1] ) {
                ans = find_seg(l , i ,a ) + find_seg(i+1, r ,a); 
                break ;
            }
        }
        return ans; 
    }
    int maxChunksToSorted(vector<int>& arr) {
        return find_seg(0 , arr.size()-1 , arr); 
    }
};