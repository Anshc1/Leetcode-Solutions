class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size(); 
        int ct[32] ; 
        memset(ct , 0 ,sizeof(ct)); 
        for(int i =0 ;i < n ; i++){
            for(int j =0 ;j < 31; j++){
                if(((nums[i]>>j)&1)){
                    ct[j]++; 
                }
            }
        }
        int ans =0 ; 
        for(int i =0 ;i < 32 ; i++){
            ans+= (ct[i]*(n-ct[i])); 
        }
        return ans; 
    }
};