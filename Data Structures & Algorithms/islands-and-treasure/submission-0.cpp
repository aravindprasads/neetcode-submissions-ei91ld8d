class Solution {
public:

    void findTreasure(vector<vector<int>> grid, queue<tuple<int, int, int>>& q) {
        for(int r=0; r<grid.size(); r++) {
            for(int c=0; c<grid[r].size(); c++) {
                if(grid[r][c] == 0)
                    q.push(make_tuple(r,c,0));
            }
        }
    }

    void bfs(vector<vector<int>>& grid, queue<tuple<int, int, int>> q) {
        unordered_set<string> visited;

        while(!q.empty()) {
            auto [row, col, val] = q.front();
            q.pop();

            string key = to_string(row) + "," + to_string(col);
            if(visited.find(key) != visited.end())
                continue;        
            visited.insert(key);
            
            grid[row][col] = val;

            vector<int>dr= {1,-1,0,0};
            vector<int>dc= {0,0,1,-1};
            for(int k=0; k<4; k++) {
                int nr = dr[k] + row;
                int nc = dc[k] + col;

                if(nr >= grid.size() || nc >= grid[nr].size())
                    continue;
                if(grid[nr][nc] == -1 || grid[nr][nc] == 0)
                    continue;

                q.push(make_tuple(nr, nc, val+1));
            }
        }
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<tuple<int, int, int>> q;
        findTreasure(grid, q);
        bfs(grid, q);                
    }
};
