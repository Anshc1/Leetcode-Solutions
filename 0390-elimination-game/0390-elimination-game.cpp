class Solution {
public:
    int curr; 
    void recur( int sz , int t ,int step){
        if(sz < 2){
            return ; 
        }
        //cout<< curr << " "; 
        if(t){
            curr+= step; 
        }else{
            if(sz%2){
               curr+= step;  
            }
        }
        sz/=2;
        recur( sz , !t , step*2 ); 
    }
    int lastRemaining(int n) {
       curr = 1 ; 
       recur(n , 1 , 1);
       return curr; 
    }
};