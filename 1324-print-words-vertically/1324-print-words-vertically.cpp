class Solution {
public:
    vector<string> printVertically(string s) {
        int n = s.size();
        vector<string>x ; 
        string t ="";  
        for(int i = 0 ; i< n ; i++){
            if(s[i] == ' '){
                x.push_back(t);
                t = ""; 
            }else{
                t+= s[i]; 
            }
        }
        if(t!= ""){
            x.push_back(t); 
        }
      
        vector<string>ans ; 
        int j = 0 ; 
        while(1){
            int k = 0 ; 
            string t(x.size() , ' ');
            for(int i = 0 ; i < x.size() ;i++){
                //cout<<x[i]<<endl;  
                if(x[i].size() > j ){
                    t[k] = x[i][j]; 
                }
                k++; 
            }
          
            j++; 
            while(!t.empty() && t.back() == ' '){
                t.pop_back(); 
            }
            if(t.empty()){
                break; 
            }
            ans.push_back(t); 
        }
        return ans; 
    }
};