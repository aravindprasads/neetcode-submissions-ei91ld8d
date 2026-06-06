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

class Solution {
public:

    int bal(TreeNode *root) {
        if(root == NULL)
            return 0;
        
        int l = bal(root->left);
        if(l == INT_MAX)
            return INT_MAX;
        int r = bal(root->right);
        if(r == INT_MAX)
            return INT_MAX;
        int diff = l-r;
        if((diff == 1) || (diff == 0) || (diff == -1))
            return max(l,r)+1;
        else
            return INT_MAX;
    }

    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        return ((bal(root) == INT_MAX)?false:true);        
    }
};
