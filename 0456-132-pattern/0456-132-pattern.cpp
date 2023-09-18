class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size(); 
        multiset<int>a ,b; 
        for(int i =1 ; i < n  ; i++){
            b.insert(nums[i]); 
        }
        a.insert(nums[0]); 
        for(int i =1 ; i < n-1 ; i++ ){
            b.erase(b.find(nums[i])); 
            auto it = b.lower_bound(nums[i]);
            if(it != b.begin()){ 
            it--;  
            if(*it < nums[i]){
                cout<< *a.begin() << endl;
                if(*a.begin() < *it){
                    return 1; 
                }
            }
            }
            a.insert(nums[i]); 
            
        }
        return 0 ; 
    }
};