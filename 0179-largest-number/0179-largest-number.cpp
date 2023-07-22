class Solution {
public:
    static bool cmp(string a , string b) {
        if (a == b) {
            return 0;
        }
        int n = a.size() , m = b.size() ;
        for (int i = 0; i < min(n , m ); ++i)
        {
            if (a[i] != b[i]) {
                return (a[i] > b[i]);
            }
        }
        return cmp(a + b , b + a);
    }
    string largestNumber(vector<int>& nums) {
        vector<string>s;
        for (auto i : nums) {
            s.push_back(to_string(i));
        }
        sort(s.begin(), s.end() , cmp );
        string ans = "";
        for (auto i : s) {
            ans += i;
        }
        if(ans[0] == '0'){
            return "0"; 
        }
        return ans;
    }
};
