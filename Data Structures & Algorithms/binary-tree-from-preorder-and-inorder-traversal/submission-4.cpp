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

    TreeNode* helper(vector<int> inorder, vector<int> preorder, int st_in, int end_in, int st_pre, int end_pre) {
        if(st_in > end_in)
            return NULL;
        
        if(st_in == end_in) {
            TreeNode *root = new TreeNode(inorder[st_in]);
            return root;
        }

        int root_val = preorder[st_pre];
        TreeNode *root = new TreeNode(root_val);

        //Left ST
        int st_in_left = st_in;
        int end_in_left;
        for(int i=st_in; i<=end_in; i++) {
            if(inorder[i] == root_val) {
                end_in_left = i-1;
                break;
            }
        }
        int st_pre_left=st_pre+1;
        int end_pre_left = st_pre_left+(end_in_left-st_in_left);
        root->left = helper(inorder, preorder, st_in_left, end_in_left, st_pre_left, end_pre_left);


        //Right ST
        int st_in_right = end_in_left+2;
        int end_in_right = end_in;
        int st_pre_right = end_pre_left+1;
        int end_pre_right = end_pre;
        root->right = helper(inorder, preorder, st_in_right, end_in_right, st_pre_right, end_pre_right);

        return root;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(inorder.size() == 0)
            return NULL;
        if(inorder.size() != preorder.size())
            return NULL;        
        return helper(inorder, preorder, 0, inorder.size()-1, 0, preorder.size()-1);
        
    }
};
