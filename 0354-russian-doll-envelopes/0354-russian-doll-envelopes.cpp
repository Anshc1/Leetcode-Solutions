class Solution {
public:
    static bool comp(vector<int>&a , vector<int>& b){
        if(a[0] == b[0]){
            return a[1] > b[1]; 
        }
        return a[0] < b[0] ; 
    }
    int maxEnvelopes(vector<vector<int>>& a) {
        sort(a.begin() , a.end() , comp);
        for(auto i : a){
            //cout<< i[0] << " " << i[1] <<endl; 
        }
        int n = a.size();
        int ans = 0;
        vector<int>x; 
        for(int i = 0; i < n ; i++){
            int idx = lower_bound(x.begin() , x.end() , a[i][1]) - x.begin(); 
            if(idx >= x.size()){
                x.push_back(a[i][1]); 
            }else{
                x[idx] = a[i][1]; 
            }
        }
        return x.size() ; 
    }
};