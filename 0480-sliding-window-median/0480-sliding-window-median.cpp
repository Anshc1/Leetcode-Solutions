class Solution {
public:
    double val(double p , double q){
        return (p+q)/2 ;
    }
    vector<double> medianSlidingWindow(vector<int>& a, int k) {
        if(k == 1){
            vector<double>res; 
            for(auto i : a){
                res.push_back(i); 
            }
            return res; 
        }
        multiset<int> p , q ; 
        int n =a.size(); 

        for(int i = 0 ; i < k ; i++){
            p.insert(a[i]); 
        }
        while(p.size() > q.size()){
            int t1 = *--p.end() ; 
            p.erase(--p.end());
            q.insert(t1); 
        }
        vector<double>ans;
        if(k%2){
            ans.push_back(*q.begin()); 
        }else{
            //cout<< *q.begin() <<endl; 
            //cout<< *--p.end() <<endl; 
            
            ans.push_back(val(*q.begin() , *--p.end())); 
        }
        int j = 0 ; 
        
        for(int i = k; i < a.size(); i++){
            if(p.find(a[j])!= p.end()){
                p.erase(p.find(a[j]));
            }else{
                q.erase(q.find(a[j])); 
            }
            j++; 
            p.insert(a[i]); 
            
            while(p.size() > q.size()){
                int t1 = *--p.end() ; 
                p.erase(--p.end());
                q.insert(t1); 
            }
            while( q.size() - p.size() > 1){
                int t1 = *q.begin() ; 
                p.erase(q.begin());
                p.insert(t1); 
            }
            
            while(*--p.end() > *q.begin()){
                
                int t1 = *--p.end(); 
                p.erase(--p.end());
                int t2 = *q.begin(); 
                q.erase(q.begin()); 
                q.insert(t1);
                p.insert(t2); 
            }
            if(k%2){
               ans.push_back(*q.begin()); 
             }else{
               ans.push_back(val(*q.begin() , *--p.end())); 
             }
            
        }
        return ans; 
    }
};