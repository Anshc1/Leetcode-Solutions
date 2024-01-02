class Solution {
public:
    void sortColors(vector<int>& nums) {
        int ct[3] = {};
        for(auto i :nums ){
            ct[i]++; 
        }
        int idx = 0 ; 
        for(int  i = 0 ; i < 3 ; i++){
            for(int j = 0; j < ct[i] ; j++){
                nums[idx] = i; 
                idx++; 
            }
        } 
    }
};