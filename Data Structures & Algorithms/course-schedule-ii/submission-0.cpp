unordered_map<int, vector<int>> makeGraph(int n, vector<vector<int>> req) {
    unordered_map<int, vector<int>> graph;    
    vector<int> vec;

    for(int i=0; i<n; i++) {
        graph[i] = vec;
    }
    for(auto it:req) {
        graph[it[1]].push_back(it[0]);
    }
    return graph;
}

void bfs(int n, unordered_map<int, vector<int>> graph, vector<int>& res) {
    vector<int> inDeg;
    for(int i=0; i<n; i++)
        inDeg.push_back(0);

    for(auto it:graph) {
        for(auto it1:it.second) {
            inDeg[it1]++;
        }
    }

    queue<int> q;

    for(int i=0; i<inDeg.size(); i++) {
        if(inDeg[i] == 0) {
            q.push(i);
            // res.push_back(i);
        }
    }

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        res.push_back(node);

        for(auto it:graph[node]) {
            inDeg[it]--;
            if(inDeg[it] == 0) {
                q.push(it);
                // res.push_back(it);
            }
        }
    }    
}

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& req) {
        unordered_map<int, vector<int>> graph;
        graph = makeGraph(numCourses, req);

        vector<int> res;
        bfs(numCourses, graph, res);

        // for(auto it:res)
        //     cout<<it<<" ";
        // cout<<endl;

        if(res.size() != numCourses)
            return vector<int>{};
        
        return res;        
    }
};
