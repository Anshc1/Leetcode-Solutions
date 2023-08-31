class Solution {
public:
    int n ; 
    unordered_map<int,int>ans; 
    vector<pair<int,int>> mergesort(vector<int>&a ,int l ,int r){
        if(l == r){
            return {{a[l] , l} }; 
        }
        
        int mid = (l+r)/2;
        
        vector<pair<int,int>> ll = mergesort(a , l, mid ); 
        vector<pair<int,int>> rr = mergesort(a , mid+1, r);
        
        int j =0 ; 
        int i =0 ; 
        vector<pair<int,int>>x ; 
        int ct =0 ; 
        for( ; i <ll.size() && j < rr.size() ; ){
            if(ll[i].first > rr[j].first){
                x.push_back(rr[j]);
                ct++; 
                j++; 
            }else{
                x.push_back(ll[i]);
                ans[ll[i].second] +=ct; 
                i++;
            }
        
        }
        while(i < ll.size()){
            x.push_back(ll[i]);
            ans[ll[i].second]+=ct;
            i++; 
        }
        while(j<rr.size()){
            x.push_back(rr[j]);
            j++ ; 
        }
        //cout<<" - - - - - -- "<<endl; 
        return x ;
        
    }
    vector<int> countSmaller(vector<int>& a) {
        n= a.size();
        ans.clear(); 
        mergesort(a , 0 , n-1);
        vector<int>b(n); 
        for(int i =0 ;i < n ; i++){
            b[i] = ans[i]; 
        }
        return b; 
    }
};