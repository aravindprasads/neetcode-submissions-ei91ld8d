//  no loop
// only 1 component 

//DFS with parent node

// create adjacency list
// take 1 node and perform DFS -> check if no loop exists
// then, check other nodes in list and all should be visited

class Solution {
public:

    bool dfs(int node, int parent, unordered_map<int, vector<int>> graph, 
             unordered_set<int>& visited) {

        if(visited.find(node) != visited.end())
            return true;

        visited.insert(node);

        for(auto it:graph[node]) {
            //check if not parent
            if(it != parent) {
                if(dfs(it, node, graph, visited) == true)
                    return true;
            }
        }

        return false;
    }

    bool checkLoop(int n, unordered_map<int, vector<int>> graph, unordered_set<int> visited) {
        int cnt = 0;
        for(auto it:graph) {
            int key = it.first;
            if(true == dfs(key, -1, graph, visited))
                    return true;
            break;
        }

        if(visited.size() != n)
            return true;
        
        return false;
    }

    unordered_map<int, vector<int>> createAdjacencyList(int n, 
                                            vector<vector<int>> edges) {
        unordered_map<int, vector<int>> graph;
        while(n) {
            vector<int>dummy;
            graph[n-1] = dummy;
            n--;
        }
        for(auto it:edges) {
            int a = it[0];
            int b = it[1];
            graph[a].push_back(b);
            graph[b].push_back(a);            
        }

        return graph;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph = createAdjacencyList(n, edges);
        unordered_set<int> visited;
        if(false == checkLoop (n, graph, visited))
            return true;
        return false;
    }
};
