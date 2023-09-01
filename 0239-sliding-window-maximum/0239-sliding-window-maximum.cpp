class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>&a, int k) {
        vector<int>x ;
        multiset<int>s ;
        int n = a.size(); 
        int j = 0; 
        for(int i =0 ; i < n ; i ++){
            s.insert(a[i]); 
            if(s.size() > k ){
                s.erase(s.find(a[j])); 
                j++; 
            }
            if(s.size() == k ){
                x.push_back(*--s.end()); 
            }
        }
        return x; 
    }
};