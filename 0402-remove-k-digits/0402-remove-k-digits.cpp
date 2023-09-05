class Solution {
public:
    string removeKdigits(string s, int k) {
        stack<int>x; 
        for(int i =0 ;i < s.size() ; i++){
            int curr  = s[i]-'0';
            while(!x.empty() && curr < x.top() && k > 0 ){
                x.pop(); 
                k--; 
            }
            x.push(curr);
        }
        while(k > 0 && !x.empty()){
            x.pop(); 
            k--;
        }
        string ans = ""; 
        while(!x.empty()){
            ans+= (char)(x.top() +'0'); 
            x.pop(); 
        }
        while(!ans.empty() && ans.back() == '0'){
            ans.pop_back(); 
        }
        if(ans == ""){
            return "0"; 
        }
        reverse(ans.begin() , ans.end()); 
        return ans; 
    }
};