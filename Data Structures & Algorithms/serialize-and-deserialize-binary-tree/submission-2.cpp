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

// 1,2,3,#,#,4,5

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        if(root == NULL)
            return ans;

        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode *node = q.front();
            q.pop();

            if(ans != "")
                ans += ",";            

            if(node == NULL) {
                ans += "#";
                continue;
            }                
            else
                ans += to_string(node->val);

            if(node->left)
                q.push(node->left);
            else {                
                q.push((TreeNode *) NULL);
            }

            if(node->right)
                q.push(node->right);
            else {                
                q.push((TreeNode *) NULL);
            }                
        }

        cout<<ans<<endl;
        return ans;
    }

    int getInt(string s) {
        int val = 0;
        for(auto it:s) {
            int num = it - '0';
            val = (val*10) + num;
        }
        return val;
    }


    vector<int> getVec(string s) {
        int i = 0;
        vector<int> vec;

        while(i < s.length()) {
            string ss = "";
            if(s[i] == ',')
                continue;
            while((i<s.length()) && (s[i] != ',')) {
                ss += s[i];
                i++;
            }
            vec.push_back(getInt(ss));            
        }
        return vec;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        if(s == "")
            return NULL;
        
        stringstream ss(s);

        string val;
        getline(ss, val, ',');
        TreeNode* root = new TreeNode(stoi(val));
        
        queue<TreeNode *> q;
        q.push(root);

        while(getline(ss, val, ',')) {
            TreeNode* node = q.front();
            q.pop();

            if(val != "#") {
                TreeNode *left = new TreeNode(stoi(val));
                node->left = left;                
                q.push(left);
            }

            getline(ss, val, ',');
            if(val != "#") {
                TreeNode *right = new TreeNode(stoi(val));
                node->right = right;                
                q.push(right);
            }
        }
        return root;
    }
};
