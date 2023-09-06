//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct node {
    string data;
    struct node *left;
    struct node *right;

    node(string x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

bool isExpression(string &s) {
    if (s == "+" or s == "-" or s == "*" or s == "/") return true;
    return false;
}



// } Driver Code Ends
/*The structure of node is as follows
struct node{
    string data;
    node *left;
    node *right;
};
*/

class Solution{
  public:
  int res(string s){
      int val = 0; 
      for(int i =s.size()-1 ; i>= 0  ; i--){
          val += pow(10 , s.size()-i-1)*(s[i]-'0');  
      }
      return val; 
  }
  int dfs(node* u){
      int a , b , val;
      if(u->left!=NULL){
          a = dfs(u->left); 
      }else{
          return res(u->data); 
      }
      if(u->right!= NULL){
          b = dfs(u->right); 
      }else{
          return res(u->data); 
      }
      if(u->data == "*"){
         return a*b; 
      }
      if(u->data == "+"){
         return a+b; 
      }
      if(u->data == "-"){
         return a-b; 
      }
      if(u->data == "/"){
         return a/b; 
      }
      
  }
  int evalTree(node* root) {
        return(dfs(root)); 
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s[n];
        for (int i = 0; i < n; i++) cin >> s[i];

        int p = 0;
        node *root = new node(s[p++]);
        queue<node *> q;
        q.push(root);
        while (!q.empty()) {
            node *f = q.front();
            q.pop();
            node *l, *r;
            if (isExpression(f->data)) {
                l = new node(s[p++]);
                r = new node(s[p++]);
                f->left = l;
                f->right = r;
                q.push(l);
                q.push(r);
            }
        }
        Solution obj;
        cout << obj.evalTree(root) << endl;
    }
}

// } Driver Code Ends