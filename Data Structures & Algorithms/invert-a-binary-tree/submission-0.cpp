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

    //         1
    //     2       3
    // 4      56       7

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return root;
        // TreeNode* l = root->left;
        // TreeNode* r = root->right;
        TreeNode* t = root->left;
        root->left = root->right;
        root->right = t;        
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
