class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int,int>>a;
        
        for(int i =0 ; i < nums.size() ; i++ ){
            for(auto j : nums[i] ){
                a.push_back({j , i }); 
            }
        }
        sort(a.begin() , a.end()); 
        set<int>x;
        int n = a.size(); 
        int m = nums.size(); 
        int j =0 ; 
        map<int,int>ct ; 
        int ans = 1e9; 
        int l  , r ;
        for(int i =0 ;i < n ; i++){
            while(j < n && x.size() < m ){
                x.insert(a[j].second); 
                ct[a[j].second]++; 
                j++; 
            }
            if(x.size() == m ){
                if(ans > a[j-1].first - a[i].first){
                    ans = a[j-1].first - a[i].first; 
                    l = a[i].first; 
                    r = a[j-1].first; 
                }
            }
            ct[a[i].second]--; 
            if(ct[a[i].second] == 0 ){
                x.erase(a[i].second); 
            }
        }
        vector<int>v = {l ,r}; 
        return v; 
    }
};