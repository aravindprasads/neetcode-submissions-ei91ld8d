/*
                1
        2               3
    4       5       #       6


    1,2,3,4,5,#,6
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL)
            return "";
        
        queue<TreeNode *> q;
        q.push(root);
        string ans = "";

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if(ans !=  "")
                ans += ",";
            if(node == NULL) {
                ans += "#";
                continue;
            }
            
            ans += to_string(node->val);
            
            if(node->left)
                q.push(node->left);
            else
                q.push(NULL);
            
            if(node->right)
                q.push(node->right);
            else
                q.push(NULL);
        }
        cout<<"asnswer"<<ans<<endl;
        return ans;
    }

    // Decodes your encoded data to tree.

    //1,2,3,4,5,6,7

    TreeNode* deserialize(string ans) {
        if(ans == "")
            return NULL;
        
        queue<TreeNode *> q;

        stringstream ss(ans);
        string val;

        getline(ss, val, ',');
        string root = val;
        TreeNode *rootnode = new TreeNode(stoi(val));
        q.push(rootnode);

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            getline(ss, val, ',');
            string left = val;
            if(left == "#")
                node->left=NULL;
            else {
                TreeNode *newnode = new TreeNode(stoi(left));
                node->left = newnode;
                q.push(newnode);
            }

            getline(ss, val, ',');
            string right = val;
            if(right == "#")
                node->right=NULL;
            else {
                TreeNode *newnode = new TreeNode(stoi(right));
                node->right = newnode;
                q.push(newnode);
            }
        }
        
        return rootnode;
    }
};
