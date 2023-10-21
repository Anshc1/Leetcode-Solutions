class Solution {
public:
    bool checkSubarraySum(vector<int>& a, int k) {
        
        int n = a.size();
        int sum = accumulate(a.begin() , a.end() , 0 ); 
        if(n < 2){
            return 0 ; 
        }
        if(sum%k == 0 ){
            return 1 ; 
        }
        vector<int>suff(n+1 , 0 ); 
        vector<int>z(n+1 , 0 ); 
        multiset<int>x; 
        for(int i = n-1 ; i >= 0 ; i--){
            suff[i] =  a[i] + suff[i+1] ; 
            z[i] =(sum - suff[i])%k;
            if(i < n-1 &&  suff[i]%k == 0 ){
                return 1; 
            }
            x.insert(z[i]); 
        }
        int p = 0; 
        x.erase(x.find(z[0])); 
        x.erase(x.find(z[1])); 
        if(x.find(0)!= x.end()){
            return 1 ; 
        }
        for(int i = 0; i < n-2 ; i++){ 
            x.erase(x.find(z[i+2]));
            p+= a[i]; 
            p%= k; 
            
            if(i >= 1 && p == 0){
                return 1; 
            }
            if(x.find(p)!= x.end()){
                return 1; 
            }
        }
        //cout<<endl; 
        return  0 ; 
    }
};