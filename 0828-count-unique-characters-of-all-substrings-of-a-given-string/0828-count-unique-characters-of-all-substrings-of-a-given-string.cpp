class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.size(); 
        vector<int>l(n , 0 ) , r(n , 0 ); 
        
        vector<int>last(26 , -1);
        
        for(int i =0 ;i < n ; i++){
            l[i] = last[s[i]-'A']; 
            last[s[i]-'A'] = i ; 
        }
        //cout<< " ok " <<endl; 
        last.assign(26 , n ); 
        for(int i = n-1 ; i >= 0 ; i--){
            r[i] = last[s[i]-'A']; 
            last[s[i]-'A'] = i ; 
        }
        int ans = 0; 
        for(int i =0 ;i < n ; i++){
            int p = i-l[i];
            int q = r[i] - i ; 
            ans+= p *q ; 
            
        }
        return ans;  
    }
};

//1 , 1 + 2 , 3 + 3 
//1 , 1 + 2 , 3 + 2

// abca b

// 1 2+1 1 + 2 + 3  1 + 2 + 3 + 2 , 1 + 2 + 3 + 2 +  1

//leetcode

//8 + 2 + 5 +  20 + 20 + 18 + 14 + 5  
//1 , 1+2 , 1 + 0 + 1 , 1 + 2 + 1 + 2