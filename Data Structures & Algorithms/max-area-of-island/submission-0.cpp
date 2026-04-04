class Solution {
public:

    int dfs(vector<vector<int>>grid, int row, int col,
            unordered_set<string>& visited) {

        string key = to_string(row) + "," + to_string(col);
        if(visited.find(key) != visited.end())
            return 0;

        visited.insert(key);
        int cnt = 1;

        vector<int> dr = {1,-1,0,0};
        vector<int> dc = {0,0,1,-1};

        for(int k=0; k<4; k++) {
            int nr = row + dr[k];
            int nc = col + dc[k];

            if(nr >= grid.size() || nc >= grid[nr].size())
                continue;
            if(grid[nr][nc] == 0)
                continue;
            
            cnt += dfs(grid, nr, nc, visited);
        }

        return cnt;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        unordered_set<string> visited;
        int maxi = 0;

        for(int r=0; r<grid.size(); r++) {
            for(int c=0; c<grid[r].size(); c++) {
                string key = to_string(r) + "," + to_string(c);
                if(visited.find(key) == visited.end()) {
                    if(grid[r][c] == 0)
                        continue;
                    int cnt = dfs(grid, r, c, visited);
                    maxi = max(maxi, cnt);
                }
            }
        }

        return maxi;        
    }
};
