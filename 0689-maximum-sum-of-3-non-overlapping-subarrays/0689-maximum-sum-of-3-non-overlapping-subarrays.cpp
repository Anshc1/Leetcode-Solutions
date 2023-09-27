class Solution {
public:
    int n ; 
    int k ; 
    vector<pair<int,int>>util(vector<int>&a ,int type  ){
        vector<int>pref(n+1 , 0 );
        pref[0] = 0; 
        for(int i =0 ;i < n ; i++){
            pref[i+1] =pref[i] + a[i];  
        }
        vector<pair<int,int>>x(n);
        int mx =0 ;
        int idx = -1; 
        for(int i =0 ;i < n ; i++){
            x[i] = {mx , idx}; 
            int r = i ; 
            int l = i - k+1;
            if(l < 0 ){
                continue; 
            }
            int sum = pref[r+1] - pref[l];
            if(type){
                if(mx < sum){
                    mx = sum ; 
                    idx = i; 
                }
            }else{
                if(mx <= sum){
                    mx = sum ; 
                    idx = i; 
                }
            }
        }
        return x ; 
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& a, int z) {
        n = a.size(); 
        k = z ; 
        vector<int>pref(n+1 , 0 );
        pref[0] = 0; 
        for(int i =0 ;i < n ; i++){
            pref[i+1] =pref[i] + a[i];  
        }
        auto l = util(a , 1 ); 
        reverse(a.begin() , a.end()); 
        auto r = util(a , 0);
        reverse(a.begin() , a.end());
        reverse(r.begin() , r.end());
        
        //for(auto i = 0 ;i < n ; i++){
            //cout<< i <<  " " << r[i].first << " " << r[i].second <<endl; 
        //}
        
        int mx =0 ;
        cout<< "ok" <<endl; 
        int i1 , i2 , i3; 
        for( int i = k ; i < n ; i++){
            if(i + k-1 >= n ){
                break ; 
            }
            
            int ll = i ; 
            int rr = i + k - 1; 
            int sum = pref[rr+1] - pref[ll];
            sum += l[ll].first;
            sum += r[rr].first;
            //cout<< r.size() <<endl; 
            //cout<< ll << " " << rr<<endl; 
            if(mx < sum ){
                mx = sum ; 
                i1 = l[ll].second-k+1;
                i2 = i ; 
                i3 = n-r[rr].second-1 ;
            }
            
        }
        vector<int>ans = {i1 ,i2 ,i3}; 
        return ans; 
    }
};