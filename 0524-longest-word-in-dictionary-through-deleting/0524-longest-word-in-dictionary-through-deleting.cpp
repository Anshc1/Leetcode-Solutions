class Solution {
public:
    string findLongestWord(string s, vector<string>& a) {
        int n = a.size(); 
        int m = s.size(); 
        vector<int>idx(n , 0 ) , ct(n , 0 ) ;
        int mx = 0 ;
        vector<string>x; 
        for(int i = 0; i < m ; i++ ){
            for(int j = 0; j < n ; j++){
                if(s[i] == a[j][idx[j]]){
                    idx[j]++; 
                }
                if( idx[j] == a[j].size()){
                    mx = max(mx , (int)a[j].size()); 
                    x.push_back(a[j]); 
                    continue; 
                }
            }
        }
        if(mx == 0 ){
            return  ""; 
        }
        //cout<<mx << endl; 
        string ans(1005 , 'z'); 
        for(auto i : x){
            if(i.size() == mx){
                ans = min(ans, i);
            }
        }
        return ans; 
    }
};