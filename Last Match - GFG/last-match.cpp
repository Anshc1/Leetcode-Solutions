//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    int findLastOccurence(string s,string t){
         int n = s.size(); 
         int m = t.size(); 
         vector<int>lcs(m+1); 
         int len = 0 ; 
         lcs[len] = 0; 
         int last =-2; 
         for(int i =1 ;i <  m; ){
             if(t[len] == t[i]){
                 len++; 
                 lcs[i] = len;
                 i++; 
             }else{
                 if(len!= 0 ){
                     len = lcs[len-1]; 
                 }else{
                     lcs[i]  = 0; 
                     i++; 
                 }
             }
         }
         for(int i =0  , j = 0 ; n-i>= m-j ;    ){
             if(s[i] == t[j]){
                 i++; 
                 j++;
             }
             if(j == m ){
                 last =  i  - j ;  
                 j= lcs[j-1]; 
             }
             else if(i < n && t[j] != s[i]){
                 if(j != 0 ){
                     j =lcs[j-1]; 
                 }else{
                     i++; 
                 }
             }
         }
         return last+1; 
         
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A>>B;
        Solution ob;
        cout<<ob.findLastOccurence(A,B)<<"\n";
        
    } 
    return 0; 
}
// } Driver Code Ends