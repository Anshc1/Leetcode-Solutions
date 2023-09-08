class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        int n = a.size();
        if(n <= 2){
            return 0;
        }
        int ans =0 ; 
        int curr = a[1] - a[0]; 
        int len =2 ; 
        for(int i =2;i < n; i++){
            if(a[i] -a[i-1] == curr){
                len ++ ;
                if(len >= 3){
                    ans+= len - 3 +1; 
                }
            }else{
                //cout << i << endl;
                //cout<< ans<< endl; 
                len = 2; 
                curr = a[i] - a[i-1] ; 
            }
        }
        return ans ; 
    }
};