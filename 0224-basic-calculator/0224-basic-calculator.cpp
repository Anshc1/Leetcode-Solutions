class Solution {
public:
    int find_val(stack<int>&x  , int num) {
        int sign = 1;
        while (!x.empty() && x.top() != -3) {
            int k = x.top();
            if (k == -1) {
                sign = -1;
            } else if (k == -2) {
                sign = 1;
            } else {
                if (sign == 1) {
                    num += k ;
                } else {
                    num -= k ;
                }
            }
            x.pop();
        }
        return num ;
    }
    void debugger(stack<int>x) {
        while (!x.empty()) {
            //dbg(x.top());
            x.pop();
        }
    }
    int calculate(string s) {
        stack<int>x ;
        int n = s.size();
        int num  = 0 ;
        int p = 0;
        bool ok = 0;
        for (int i = n - 1 ; i >= 0 ; ) {
            if (s[i] == ')') {
                x.push(-3);
                num = 0 ;
                p = 0 ;
                ok = 0 ;
            } else if (s[i] == '(') {
                num = find_val(x , num);
                x.pop();
                x.push(abs(num));
                if (i > 0 && num < 0 ) {
                    if (s[i - 1] == '+') {
                        x.push(-1);
                    } else {
                        x.push(-2);
                    }
                    i--;
                }
                if(i == 0 && num < 0 ){
                    x.push(-1); 
                }
                num = 0 ;
                p = 0 ;
                ok = 0 ;
            } else if (s[i] == '+') {
                if (ok) {
                    x.push(num);
                }
                x.push(-2);
                num = 0 ;
                p = 0 ;
                ok = 0 ;
            } else if (s[i] == '-') {
                if (ok) {
                    x.push(num);
                }
                x.push(-1);
                num = 0 ;
                p = 0 ;
                ok = 0;
            } else if (s[i] == ' ') {
                if (ok) {
                    x.push(num);
                }
                num = 0 ;
                p = 0 ;
                ok = 0 ;
            } else {
                ok = 1;
                num += (s[i] - '0') * pow(10 , p );
                p++ ;
            }
            //dbg(i);
            //debugger(x);
            i--;
        }
        if(ok){
            x.push(num); 
        }
        
        int ans =  find_val(x , 0 );
        return ans;
    }
};