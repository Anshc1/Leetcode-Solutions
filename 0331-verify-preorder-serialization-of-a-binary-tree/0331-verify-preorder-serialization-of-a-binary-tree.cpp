class Solution {
public:

    bool isValidSerialization(string s) {
       stringstream ss ; 
       ss << s ;
       string t ; 
       int d = 1; 
       while(getline(ss, t , ',')){
           d--; 
           if(d < 0 ){
               return 0  ;
           }
           if(t[0] != '#'){
              d+=2;    
           }
       }
       return d == 0 ; 
    }
};