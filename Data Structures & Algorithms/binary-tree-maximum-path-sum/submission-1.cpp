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

    int helper(TreeNode *root, int& maxi) {
        if(root == NULL)
            return INT_MIN;
        
        int l = helper(root->left, maxi);
        if(l < 0) l = 0;
        int r = helper(root->right, maxi);
        if(r < 0) r = 0;

        maxi = max(maxi, l+r+root->val);

        return (max(l,r) + root->val);
        
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        helper(root, maxi);
        return maxi;
    }
};
