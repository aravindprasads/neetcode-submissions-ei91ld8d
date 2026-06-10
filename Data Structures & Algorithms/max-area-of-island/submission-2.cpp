class Solution {
public:

    int dfs(int row, int col, vector<vector<int>> grid, unordered_set<string>& visited) {
        string key = to_string(row) + "," + to_string(col);
        if(visited.find(key) != visited.end())
            return 0;
        visited.insert(key);
        int cnt = 1;

        
        // 1,0
        // -1,0
        // 0,1
        // 0,-1

        vector<int> dr = {1, -1, 0, 0};
        vector<int> dc = {0, 0, 1, -1};

        for(int k=0; k<4; k++) {
            int nr = dr[k] + row;
            int nc = dc[k] + col;

            if(nr >= grid.size() || nc >= grid[nr].size() || nr<0 || nc<0)
                continue;

            if(grid[nr][nc] == 0)
                continue;

            cnt += dfs(nr, nc, grid, visited);
        }
        return cnt;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        unordered_set<string> visited;
        int maxi = 0;

        for(int r=0; r<grid.size(); r++) {
            for(int c=0; c<grid[r].size(); c++) {
                if(grid[r][c] == 1) {
                    string key = to_string(r) + "," + to_string(c);
                    if(visited.find(key) == visited.end()) {
                        maxi = max(maxi, dfs(r, c, grid, visited));
                    }
                }
            }
        }
        return maxi;
    }
};