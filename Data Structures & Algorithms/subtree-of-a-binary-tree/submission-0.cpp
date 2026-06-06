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

    bool check(TreeNode* p, TreeNode* q) {
        if(!p && !q)
            return true;
        if(p && !q)
            return false;
        if(!p && q)
            return false;
        return ((p->val == q->val) &&
                check(p->left, q->left) &&
                check(p->right, q->right));
    }

    bool isSubtree(TreeNode* p, TreeNode* q) {
        if(q == NULL)
            return false;
        if(p == NULL) return false;
        if(p->val == q->val) {
            if(check(p, q))
                return true;
        }
        if(isSubtree(p->left, q))
            return true;
        if(isSubtree(p->right, q))
            return true;
        return false;        
    }
};
