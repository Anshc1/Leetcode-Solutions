class Solution {
public:
    int ans = 0 ; 
    void count_val(vector<int>&a , int st , int end ,int mid){
        int l = st ,r = mid+1 ; 
        while(l <=mid && r <= end){
            if((long)a[l] > (long)a[r]*2){
                ans+= (mid - l+1); 
                r++; 
            }else{
                l++; 
            }
        }
        sort(a.begin() + st , a.begin() + end +1 ); 
    }
    void merge_s(vector<int>&a , int st ,int end ){
        if(st == end){
            return ; 
        }
        int mid = (st + end)/2; 
        merge_s(a , st , mid ); 
        merge_s(a ,mid+1 ,end); 
        count_val(a ,st ,end , mid); 
    }
    int reversePairs(vector<int>& nums) {
        ans =0 ; 
        merge_s(nums , 0  , nums.size()-1) ;
        return ans ; 
    }
};