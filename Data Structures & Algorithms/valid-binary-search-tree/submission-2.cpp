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

    bool helper(TreeNode *root, int mini, int maxi) {
        if(root == NULL)
            return true;
        
        if((mini >= root->val) || (root->val >= maxi))
            return false;
        
        return (helper(root->left, mini, root->val) && helper(root->right, root->val, maxi));
    }


    bool isValidBST(TreeNode* root) {        
        return helper(root, INT_MIN, INT_MAX);
    }
};
