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

    int helper(TreeNode* root) {
        if(root == NULL)
            return true;
        int l = helper(root->left);
        if(l == INT_MAX)
            return INT_MAX;
        int r = helper(root->right);
        if(r == INT_MAX)
            return INT_MAX;

        int diff = l-r;

        if((diff == 0) || (diff == 1) || (diff == -1))
            return max(l,r)+1;
        return INT_MAX;
    }

    bool isBalanced(TreeNode* root) {
        if(INT_MAX == helper(root))
            return false;
        return true;
    }
};
