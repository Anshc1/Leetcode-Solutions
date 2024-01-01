class Solution {
public:
    bool check(string s , string t ){
        //cout<< s << " " << t<<endl; 
        int m1 = (s[2]-'0')*10 + s[3]-'0' ;
        int m2 = (t[2]-'0')*10 + t[3]-'0' ;
        int h1 = (s[0]-'0')*10 + s[1]-'0' ;
        int h2 = (t[0]-'0')*10 + t[1]-'0' ;
        //cout<< h1 << ' ' << h2<<endl; 
        if(h2 < h1 || h2 - h1 > 1){
            return 0 ; 
        }
        if(h2 - h1 == 1){
            int d = m2 - m1 ; 
            if(d < 0 ){
                d+= 60 ; 
            }else{
                return 0 ; 
            }
            if(d >= 60){
                return 0 ; 
            }
        }
        return 1; 
    }
    vector<string> findHighAccessEmployees(vector<vector<string>>& a) {
        unordered_map<string , vector<string>>x ; 
        for(auto i : a){
            x[i[0]].push_back(i[1]); 
        } 
        vector<string>ans; 
        for(auto i : x){
            sort(i.second.begin() , i.second.end());
            if(i.second.size() < 3){
                continue; 
            }
            for(int j = 0; j < i.second.size()-2 ; j++){
                if(check(i.second[j] , i.second[j+2] )){
                    ans.push_back(i.first); 
                    break; 
                }
            }
        }
        return ans; 
    }
};