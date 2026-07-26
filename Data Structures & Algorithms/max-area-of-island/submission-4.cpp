class Solution {
public:

    int dfs(vector<vector<int>> grid, unordered_set<string>& visited, int row, int col) {
        string key = to_string(row) + "," + to_string(col);
        if(visited.find(key) != visited.end())
            return 0;
        visited.insert(key);
        int cnt = 1;

        /*
        0,0

        1,0
        -1,0
        0,1
        0,-1
        */

        vector<int>dr = {1, -1, 0, 0};
        vector<int>dc = {0, 0, 1, -1};

        for(int k=0; k<4; k++) {
            int nr = dr[k] + row;
            int nc = dc[k] + col;

            if((nr < 0) || (nc < 0) || (nr >=grid.size()) || (nc >= grid[row].size())) 
                continue;

            if(grid[nr][nc] == 0)
                continue;
            
            cnt += dfs (grid, visited, nr, nc);
        }
        return cnt;
    }

    int bfs(vector<vector<int>> grid, unordered_set<string>& visited, int row, int col) {
        string key = to_string(row) + "," + to_string(col);
        if(visited.find(key) != visited.end())
            return 0;
        
        queue<pair<int, int>> q;
        q.push({row, col});
        int cnt = 0;

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            string key = to_string(r) + "," + to_string(c);
            if(visited.find(key) != visited.end())
                continue;            
            visited.insert(key);
            cnt++;

            /*
            0,0

            1,0
            -1,0
            0,1
            0,-1
            */

            vector<int> dr = {1,-1,0,0};
            vector<int> dc = {0,0,1,-1};
            for(int k=0; k<4; k++) {
                int nr = dr[k] + r;
                int nc = dc[k] + c;

                if((nr < 0) || (nr >= grid.size()) || (nc < 0) || (nc >= grid[r].size()))
                    continue;
                if(grid[nr][nc] == 0)
                    continue;
                q.push({nr, nc});
            }            
        }

        return cnt;
    }





    int maxAreaOfIsland(vector<vector<int>>& grid) {
        unordered_set<string> visited;
        int maxi = 0;

        for(int r=0; r<grid.size(); r++) {
            for(int c=0; c<grid[r].size(); c++) {
                if(grid[r][c] == 0)
                    continue;
                string key = to_string(r) + "," + to_string(c);
                if(visited.find(key) != visited.end())
                    continue;
                maxi = max (maxi, bfs(grid, visited, r, c));
            }
        }

        return maxi;
    }
};