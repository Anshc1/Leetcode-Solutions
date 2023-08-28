class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        vector<int>lis;
        
        for(int i =0 ;i < a.size(); i++){
            int idx = lower_bound(lis.begin(), lis.end() ,a[i]) - lis.begin();
            if(idx >= lis.size()){
                lis.push_back(a[i]);
            }else{
                lis[idx] = a[i]; 
            }
        }
        return lis.size() ; 
    }
};