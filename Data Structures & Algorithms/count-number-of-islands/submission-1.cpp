class Solution {
public:

    void dfs(int row, int col, vector<vector<char>> grid, unordered_set<string>& visited) {
        // cout<<row<<" "<<col<<" "<<endl;
        string key = to_string(row) + "," + to_string(col);
        if(visited.find(key) != visited.end())
            return;
        visited.insert(key);
        // 0,0

        // 0,1
        // 0,-1
        // 1,0
        // -1,0

        vector<int> dr = {0,0,1,-1};
        vector<int> dc = {1,-1,0,0};

        for(int k=0; k<4; k++) {
            int nr = dr[k] + row;
            int nc = dc[k] + col;

            if(nr >= grid.size() || nc >= grid[nr].size() || nr < 0 || nc < 0)
                continue;
            if(grid[nr][nc] != '1')
                continue;
            dfs(nr, nc, grid, visited);
        }
    }


    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0)
            return 0;
        unordered_set<string> visited;
        int cnt = 0;
        for(int r=0; r<grid.size(); r++) {
            for(int c=0; c<grid[r].size(); c++) {
                if(grid[r][c] == '1') {
                    string key = to_string(r) + "," + to_string(c);
                    if(visited.find(key) == visited.end()) {
                        dfs(r, c, grid, visited);
                        cnt++;
                    }
                }
            }
        }

        return cnt;
    }
};
