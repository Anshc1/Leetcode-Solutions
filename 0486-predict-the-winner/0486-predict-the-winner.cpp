class Solution {
public:
    vector<int>a ; 
    bool recur(int i , int j , int t ,int p , int q  ){
        //cout<< i << " " << j << " " << p << " " << q << " " << t<<endl; 
        if(i > j){
            if(p >= q){
                return 1; 
            }
            return 0 ; 
        }
        int res = 0 ; 
        if(t){
            res = 1; 
            res&= recur(i+1 , j , !t , p , q+a[i]); 
            res&= recur(i , j-1 , !t , p , q+a[j]);
        }else{
            res|= recur(i+1 , j , !t , p+a[i] , q); 
            res|= recur(i , j-1 , !t , p+a[j] , q); 
        }
        return res; 
    }
    bool predictTheWinner(vector<int>& nums) {
        a =nums; 
        return recur(0 , nums.size()-1 , 0 , 0 , 0 ); 
        
    }
};