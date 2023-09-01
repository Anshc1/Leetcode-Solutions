class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>&a, int k) {
        vector<int>x ;
        deque<int>q ; 
        int n = a.size(); 
        for(int i = 0; i < n ; i++){
            if(!q.empty() && q.front() == i - k ){
                q.pop_front(); 
            }
            while(!q.empty() && a[q.back()] < a[i] ){
                q.pop_back(); 
            }
            q.push_back(i);
            if(i - k + 1 >= 0 ){
                x.push_back(a[q.front()]);
            }
        }
        return x; 
    }
};