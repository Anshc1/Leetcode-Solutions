class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        stack<int>x;
        int n = a.size();
        vector<int>left(n, 0 ) , right(n , 0 );
        left[0] = a[0];
        x.push(0); 
        for (int i = 0; i < n ; i++) {
            while (!x.empty() && a[x.top()] >= a[i]) {
                x.pop();
            }
            if (!x.empty()) {
                int len = i -  x.top();
                left[i] = len * a[i];
            } else {
                left[i] = (i + 1) * a[i];
            }
            x.push(i) ; 
        }
        right[n - 1] = a[n - 1];
        stack<int>y;
        y.push(n - 1);
        for (int i = n - 2 ; i >= 0 ; i--) {
            while (!y.empty() && a[y.top()] >= a[i]) {
                y.pop();
            }
            if (y.empty()) {
                right[i] = (n - i)*a[i]; 
            }else{
                right[i] = (y.top() - i ) * a[i];  
            }
            y.push(i); 
        }
        int ans = 0; 
        for(int i = 0; i < n ; i++){
            
            ans = max(ans, left[i] + right[i] - a[i]); 
        }
        return ans; 
    }
};