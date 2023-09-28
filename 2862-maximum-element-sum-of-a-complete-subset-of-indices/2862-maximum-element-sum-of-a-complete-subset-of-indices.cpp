class Solution {
public:
    unordered_map<int,int> primes(int n ){
        unordered_map<int,int>x; 
        for(int i = 2 ;i*i <= n ; i++){
            while(n%i == 0 ){
                x[i]++;
                n/=i ; 
            }
        }
        if(n >= 2){
            x[n]++; 
        }
        return x ;
    }
    
    long long maximumSum(vector<int>& a) {
        int n = a.size(); 
        unordered_map<int,long long>ct;
        long long ans = 0; 
        for(int i =0 ; i < n ; i++){
            auto mp = primes(i+1);
            int val = 1; 
            for(auto j : mp){
                if(j.second%2){
                    val*= j.first; 
                }
            }
            ct[val]+= a[i]; 
            ans = max(ans , ct[val]); 
        }
        return ans; 
    }
    
};