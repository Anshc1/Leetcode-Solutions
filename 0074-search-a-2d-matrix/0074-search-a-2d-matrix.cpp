class Solution {
public:
    
    bool bs(vector<int>x , int t){
        int l = 0 ,  r = x.size()-1; 
        while(l<= r){
            int mid = (l+r)>>1; 
            if(x[mid] > t){
                r = mid-1; 
            }else if(x[mid] < t){
                l = mid+1 ; 
            }else{
                return 1; 
            }
        }
        return 0 ; 
    }
    bool searchMatrix(vector<vector<int>>& a, int t) {
        int l = 0 , r = a.size()-1; 
        while(l <= r){
            int mid = (l+r)>>1; 
            if(t >= a[mid][0] && t <= a[mid].back() ){
                bool check = bs(a[mid] , t);
                if(check){
                    return 1; 
                }else{
                    return 0 ; 
                }
            }
            else if(t < a[mid][0] ){
                r = mid-1; 
            }else{
                l = mid+1; 
            }
        }
        return 0 ; 
    }
    // 0 9 
    //5 
    //2
    //1
    
};