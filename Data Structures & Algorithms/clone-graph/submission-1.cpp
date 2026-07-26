/*
each node
create new-node
go their neighbors
after processing, add neigh to node's list
have visited
*/


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    Node *helper(Node* node,  unordered_map<Node *, Node *>& visMap) {
        if(visMap.find(node) != visMap.end())
            return visMap[node];
        Node *copyNode = new Node(node->val);        
        visMap[node]= copyNode;
        for(auto it:node->neighbors) {
            copyNode->neighbors.push_back(helper(it, visMap));
        }
        return copyNode;
    }

    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return NULL;
        unordered_map<Node *, Node *> visMap;
        return helper(node, visMap);
    }
};