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

    int helper(TreeNode* root, int k, int& cnt) {
        if(root == NULL)
            return INT_MAX;
        int l = helper(root->left, k, cnt);
        if(l != INT_MAX)
            return l;            
        cnt++;
        // cout<<root->val<<" "<<cnt<<endl;
        if(cnt == k) {
            // cout<<"found"<<endl;
            return root->val;
        }

        return helper(root->right, k, cnt);        
    }

    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        return helper(root, k, cnt);
    }
};