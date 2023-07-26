class Solution {
public:
    int canCompleteCircuit(vector<int>& a, vector<int>& b) {
        int n = a.size(); 
        int val= 0 ;
        int ans = 0; 
        int tg =0 ; 
        int tc = 0 ; 
        for(int i = 0 ; i< n ; i++){
            val+= a[i] - b[i];
            tg+= a[i]; 
            tc+= b[i]; 
            if(val < 0 ){
                ans =  i+1; 
                val = 0 ; 
            }
        }
        return (tg >= tc )? ans : -1;  
    }
};