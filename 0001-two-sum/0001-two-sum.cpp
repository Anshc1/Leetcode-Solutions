class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>x; 
        int n = nums.size(); 
        for(int i = 0; i < n ; i++){
            x[nums[i]] = i+1;
        }
        vector<int>a; 
        for(int i = 0; i < n ; i++){
            int j = x[target - nums[i]]-1 ;
            if( j >=0 && j!= i  ){
                a = {min(i , j ) , max(i , j ) }; 
                return a ; 
            }
        }
        return a; 
    }
};