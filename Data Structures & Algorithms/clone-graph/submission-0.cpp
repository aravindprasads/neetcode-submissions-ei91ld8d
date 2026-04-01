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


//create 1-1 mapping
//then, just make the links through a traversal


class Solution {
public:

    Node* dfs(Node *node, unordered_map<Node *, Node *>& joinMap, 
             unordered_set<Node *>& visited) {
        if(node == NULL)
            return NULL;

        if(visited.find(node) != visited.end())
            return joinMap[node];

        visited.insert(node);
        Node *newNode = new Node;
        newNode->val = node->val;

        joinMap[node] = newNode;

        for(auto it:node->neighbors) {
            newNode->neighbors.push_back(dfs(it, joinMap, visited));
        }

        return joinMap[node];
    }

    void copyNeighbors(Node *node, unordered_map<Node *, Node *> joinMap) {
        if(node == NULL)
            return;

        Node *newNode = joinMap[node];
        for(auto it: node->neighbors) {
            newNode->neighbors.push_back(joinMap[it]);
            copyNeighbors(it, joinMap);
        }
    }

    Node* cloneGraph(Node* node) {

        if(node == NULL)
            return NULL;

        unordered_set<Node *> visited;
        unordered_map<Node *, Node *> joinMap;

        dfs(node, joinMap, visited);

        // copyNeighbors(node, joinMap);

        return joinMap[node];      
    }
};
