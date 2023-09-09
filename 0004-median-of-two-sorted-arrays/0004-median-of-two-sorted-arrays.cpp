class Solution {
public:
    int recur(int l1 , int r1 , int l2 , int r2, vector<int>&a , vector<int>&b , int t){
        if(l1 > r1){
            return b[t - l1]; 
        }
        
        if(l2 > r2){
            return a[t-l2]; 
        }
        int m1 = (l1+ r1)/2 ; 
        int m2 = (l2+ r2)/2 ;
        
        if(m1 + m2 < t){
            if(a[m1] > b[m2]){
                return recur(l1 , r1 , m2+1,r2 , a,b , t ); 
            }else{
                return recur(m1+1 , r1 , l2, r2 ,a, b , t ); 
            }
        } else{
            if(a[m1] > b[m2] ){
                return recur(l1 , m1-1 , l2 , r2 ,a,b ,t); 
            }else{
                return recur(l1 , r1 ,l2 , m2-1 , a , b ,t); 
            }
        }
        return -1 ; 
    }
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int t = a.size() + b.size(); 
        if(t%2==0){
            return 1.0 * (recur(0 , a.size()-1 , 0 , b.size()-1 , a , b ,t/2)  + recur(0 , a.size()-1 , 0 , b.size()-1 , a , b ,t/2 - 1))/2; 
        }else{
            return 1.0 * recur(0 , a.size()-1 , 0 , b.size()-1 , a , b ,t/2); 
        }
    }
};