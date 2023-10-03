class Solution {
public:
    int find_seg(int l , int  r , vector<int>&a){
        //cout<< l << " " << r<<endl;  
        multiset<int>x; 
        for(int i =l  ; i <= r ; i ++){
            x.insert(a[i]); 
        }
        int mx = 0 ; 
        int ans =1 ; 
        for(int i = l  ;i <  r ; i++){
            x.erase(x.find(a[i]));
            mx = max(mx , a[i]); 
            if(mx <= *x.begin()){
                ans = find_seg(l , i ,a ) + find_seg(i+1, r ,a); 
                break ;
            }
        }
        return ans; 
    }
    int maxChunksToSorted(vector<int>& arr) {
        return find_seg(0 , arr.size()-1 , arr); 
    }
};