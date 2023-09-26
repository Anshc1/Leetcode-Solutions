class Solution {
public:
    static bool comp(vector<int>&a , vector<int>&b){
        return a[1] < b[1]; 
    }
    int scheduleCourse(vector<vector<int>>& a) {
        sort(a.begin() , a.end() , comp); 
        priority_queue<int>q;
        int t = 0 ; 
        int n = a.size(); 
        for(int i =0 ; i < n  ; i++){
            q.push(a[i][0]);
            t+= a[i][0]; 
            if(t > a[i][1]){
                t-= q.top(); 
                q.pop(); 
            }
        }
        return q.size(); 
    }
};