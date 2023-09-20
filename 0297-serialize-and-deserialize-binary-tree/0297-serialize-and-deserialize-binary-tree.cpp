/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
   string serialize(TreeNode* root) {
        string s ;
        s = "";
        queue<TreeNode*>q;
        q.push(root);
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            if (t == NULL) {
                s += "1001";
                s += ',';
                continue;
            }else{
                s+= to_string(t->val) ;
                s+= ','; 
            }
            q.push(t->left);
            q.push(t->right);
        }
        s.pop_back(); 
        return s ;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int val ;
        stringstream ss(data);
        vector<int>x ;
        while (ss >> val) {
            x.push_back(val);
            if (ss.peek() == ',') {
                ss.ignore();
            }
        }
        if(x[0] == 1001){
            return NULL; 
        }
        TreeNode* root = new TreeNode(x[0]);
        queue<TreeNode*>q;
        q.push(root);
        int ct = 0 ;
        
        for (int i = 1; i < x.size() ; i++) {
            auto curr = q.front();
            if (ct == 0 ) {
                if (x[i] == 1001) {
                    //curr->left = NULL;
                } else {
                    TreeNode* nw = new TreeNode(x[i]);
                    curr->left = nw;
                    q.push(nw);
                }
                ct = 1;
            } else {
                if (x[i] == 1001) {
                    //curr->right = NULL;
                } else {
                    TreeNode* nw = new TreeNode(x[i]);
                    curr->right = nw;
                    q.push(nw);
                }
                q.pop();
                ct = 0;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));