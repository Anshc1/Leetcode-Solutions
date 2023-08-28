//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int j =0 ;
        int n = s.size(); 
        set<int>x ; 
        int ans =-1; 
        map<int,int>ct; 
        for(int i =0; i < n ; i++){
            x.insert(s[i]-'a');
            ct[s[i]-'a']++; 
            while(j < i && x.size() > k){
                ct[s[j]-'a']--; 
                if(ct[s[j]-'a']== 0 ){
                    x.erase(x.find(s[j]-'a')); 
                }
                j++; 
            }
            if(x.size() == k ){
                ans= max(ans, i - j+1); 
            }
        }
        return ans; 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends