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

    void trav(TreeNode* root, int maxi, int& count) {
        if(root == NULL)
            return;
        if(root->val >= maxi)
            count++;
        trav(root->left, max(maxi, root->val), count);
        trav(root->right, max(maxi, root->val), count);
    }

    int goodNodes(TreeNode* root) {
        int maxi = INT_MIN;
        int count = 0;
        trav(root, maxi, count);
        return count;
    }
};
