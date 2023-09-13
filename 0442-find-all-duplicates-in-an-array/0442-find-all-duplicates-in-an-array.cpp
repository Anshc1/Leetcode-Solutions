class Solution {
public:
    vector<int> findDuplicates(vector<int>& a) {
        int n = a.size();
        for (int i = 0 ; i < n ; i++) {
            int k = a[i];
            if (k >= 1e6) {
                k -= 1e6;
            }
            if(k >= 1e6){
                k-=1e6; 
            }
            a[k - 1] += 1e6;
            //cout<< i<<" " << k <<endl; 
        }
        vector<int>ans;
        int mx = 1e6;
        for (int i = 0 ; i < n ; i++) {
            if (a[i] / mx  == 2) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};
