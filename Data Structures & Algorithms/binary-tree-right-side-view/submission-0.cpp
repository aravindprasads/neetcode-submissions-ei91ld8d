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

    void trav(TreeNode* root, int level, map<int, int>& hash) {
        if(root == NULL)
            return;
        hash[level] = root->val;
        trav(root->left, level+1, hash);
        trav(root->right, level+1, hash);
    }


    vector<int> rightSideView(TreeNode* root) {

        if(root == NULL)
            return vector<int>{};

        map<int, int> hash;
        trav(root, 0, hash);

        vector<int> ans;
        for(auto it:hash) {
            ans.push_back(it.second);
        }
        return ans;
    }
};
