class Solution {
public:
    int find_ans(vector<int>&a){
        vector<int>lis; 
        for(auto i: a){
            auto idx = upper_bound(lis.begin() , lis.end() , i)-lis.begin(); 
            if(idx < lis.size()){
                lis[idx] = i ; 
            }else{
                lis.push_back(i); 
            }
        }
        return lis.size(); 
    }
    int kIncreasing(vector<int>& a, int k) {
        int n = a.size(); 
        int ans = 0  ;
        for( int i =0 ;i < k ;i++){
            vector<int>b; 
            for(int j = i ; j < n ; j+=k ){
                b.push_back(a[j]); 
            }
            ans+= b.size() - find_ans(b);
        }
        return ans; 
    }
};