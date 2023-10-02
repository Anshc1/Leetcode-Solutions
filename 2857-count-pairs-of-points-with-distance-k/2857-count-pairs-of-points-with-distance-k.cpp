class Solution {
public:
    int countPairs(vector<vector<int>>&c, int k) {
        map<int,map<int,int>>ct; 
        int n = c.size(); 
        int ans = 0; 
        for(int i = n-1; i >= 0 ; i--){
            for(int j = 0; j <= k ; j++){
                int k1 = j ;
                int k2 = k - j ; 
                int x2 = k1^c[i][0];
                int y2 = k2^c[i][1]; 
                ans+= ct[x2][y2]; 
            }
            ct[c[i][0]][c[i][1]]++; 
        }
        return ans; 
    }
};