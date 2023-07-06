/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root){
            return root; 
        }
        Node* curr = root ; 
        queue<pair<Node*,int>>q; 
        q.push({curr , 0});
        while(!q.empty()){
            int n = q.size(); 
            Node* prev = NULL; 
            for(int i = 0 ; i< n ; i++){
                auto u = q.front(); 
                q.pop(); 
                if(u.first->left != NULL){
                    q.push({u.first->left , u.second+1}); 
                }
                if(u.first->right != NULL){
                    q.push({u.first->right , u.second+1}); 
                }
                if(prev != NULL){
                    prev->next = u.first; 
                }
                prev = u.first; 
            }
            prev->next = NULL; 
        }
        return root; 
    }
};