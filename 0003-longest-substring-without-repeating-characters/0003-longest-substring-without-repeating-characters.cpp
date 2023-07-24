class Solution {
public:
    
int lengthOfLongestSubstring(string a) {
    map<char,int>cnt ;
    int j = 0 ; 
    int ans = 0; 
    for(int i = 0; i < a.size() ; i++){
        cnt[a[i]]++;
        if(cnt[a[i]] == 2){
            while(cnt[a[i]] == 2){
                cnt[a[j]]--; 
                j++;
            }
        }
        //cout<< i << " " << j <<endl; 
        ans = max(ans , i - j  +1); 
    }
    return ans; 
}
};