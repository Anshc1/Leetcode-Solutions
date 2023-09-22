class Solution {
public:
    vector<int> check(vector<int>&a  ,int sum ){
        int n = a.size(); 
        int mx = 1<< n ; 
        mx--; 
        vector<int>res; 
        //cout<< mx << endl; 
        for(int i = 1; i < mx ; i++){
            int p = 0 , q =0 ; 
            for(int j = 0; j < a.size(); j++){
                p+= (((i>>j)&1)? a[j] :  0);
                q+= (((i>>j)&1)? 0 :  a[j]);
            }
            if(p == q){
                 res.push_back(i); 
            }
        }
        return res ; 
    }
    bool makesquare(vector<int>& a) {
        int sum = 0  ; 
        for(auto i : a){
            sum += i ; 
        }
        if(sum % 4 != 0 ){
            return 0 ; 
        }
        sum/= 4; 
        vector<int>x = check(a ,sum*2 ); 
        for(auto i : x){
            vector<int>p , q ; 
            for(int j =0 ; j < a.size() ; j++ ){
                if(((i>>j)&1)){
                    p.push_back(a[j]); 
                }else{
                    q.push_back(a[j]); 
                }
            }
            if(!check(p , sum).empty() && !check(q , sum ).empty()){
                return 1; 
            }
        }
        return 0 ; 
    }
};