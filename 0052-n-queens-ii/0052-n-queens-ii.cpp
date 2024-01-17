class Solution {
public:
    int n ; 
    bool check(int a , int b , int x , int y){
        a-= x; 
        b-= y; 
        return ((abs(a) == abs(b)) ||(a == 0 ) || (b== 0 )) ;
    }
    int recur(int i , int j , vector<pair<int,int>>&a  , int t  ){
        if(t == 0 ){
            return 1; 
        }
        if(i >=n || j>= n ){
            return 0 ; 
        }
        int res  = 0 ; 
        res+= recur(i , j+1 , a , t);
        bool ok = 1; 
        for(auto p : a){
            if(check(p.first , p.second , i , j)){
                ok = 0; 
                break; 
            }
        }
        if(ok){
            a.push_back({i, j}); 
            res+= recur(i+1 , 0 , a , t-1); 
            a.pop_back(); 
        }
        return res; 
    }
    int totalNQueens(int n) {
        this->n = n ; 
        vector<pair<int,int>>a ; 
        return recur(0 , 0 , a , n); 
    }
};