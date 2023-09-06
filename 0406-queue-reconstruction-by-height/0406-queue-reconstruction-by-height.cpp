class Solution {
public:
    
    static bool comp(vector<int>&a , vector<int>&b){
        if(a[0] == b[0]){
            return a[1] < b[1]; 
        }
        return a[0] > b[0]; 
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& a) {
        sort(a.begin() , a.end() , comp);
        int n = a.size(); 
        vector<vector<int>>res ; 
        for(int i =0 ; i < n ; i++ ){
            res.insert(res.begin() + a[i][1] , a[i]); 
        }
        return res ; 
    }
};