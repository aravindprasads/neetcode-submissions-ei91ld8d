class Solution {
public:

    unordered_map<int, vector<int>> makeGraph(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;
        vector<int> vec;

        for(int i=0; i<n; i++)
            graph[i] = vec;
        
        for(auto it:edges) {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }

        return graph;
    }

    bool dfs(unordered_map<int, vector<int>> graph, unordered_set<int>& visited,
             int node, int par) {

        if(visited.find(node) != visited.end())
            return false;
        visited.insert(node);

        for(auto it:graph[node]) {
            if(it != par) {
                if(false == dfs(graph, visited, it, node))
                    return false;
            }
        }

        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;
        graph = makeGraph(n, edges);

        unordered_set<int> visited;
        if(false == dfs(graph, visited, 0, -1))
            return false;
        
        if(visited.size() != n)
            return false;
        
        return true;
    }
};
