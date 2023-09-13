class Solution {
public:
    
    int numberOfArithmeticSlices(vector<int>& a) {
        map<int,int>ct; 
        int ans =0 ; 
        for(auto i : a){
            ct[i]++; 
        }
        for(auto i : ct){
            if(i.second< 2){
                continue; 
            }
            ans+= pow(2 , i.second ) - i.second - 1 - i.second*(i.second-1)/2 ; 
        }
        int n = a.size(); 
        vector<unordered_map<long long ,int >>dp(n ); 
        for(int i = 1; i < n ; i++){
            for(int j = i-1; j>=0 ; j--){
                if(a[i] == a[j]){
                    continue; 
                }
               
                long long d = (long long)a[i]-a[j];
                
                dp[i][d] = dp[i][d] +  dp[j][d] + 1  ; 
                ans+= dp[j][d] ; 
            }
            //cout<<ans<<endl;
        }
        return ans; 
    }
};