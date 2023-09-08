class Solution {
public:
    bool canPartition(vector<int>& a) {
        int n = a.size();
        int sum = 0;
        for (int i = 0 ; i < n ; i++) {
            sum += a[i];
        }
        int dp[sum+1]; 
        memset(dp , 0 , sizeof(dp)); 
        dp[0] = 1;
        
        for (int i = 0; i < n ; i++) {
            int temp[sum+1] ;
            memset(temp , 0 ,sizeof(temp) ); 
            for (int k = 0 ; k <= sum ; k++) {
                temp[k] |= dp[k];
                if (dp[k] && k+a[i] <= sum) {
                    temp[k + a[i]] |= 1 ;
                }
            }
            for(int k =0 ;k<= sum ;k++){
                dp[k] = temp[k]; 
            }
        }
       
        if (sum % 2) {
            return 0 ;
        }
        return dp[sum / 2] ;
    }
};