class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size(); 
        int mask =0 ; 
        int ans =0 ; 
        for(int i =30 ;i >= 0  ; i--){
            mask|= 1<<i ; 
            set<int>x ;
            for(auto j : nums){
                x.insert(j&mask); 
            }
            int curr  = ans|(1<<i);
            for(auto j : x){
                if(x.find(j^curr)!= x.end()){
                    ans= curr; 
                    break; 
                }
            }
        }
        return ans; 
    }
};