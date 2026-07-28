class Solution {
public:

    int bfs(vector<vector<int>>& grid) {

        queue<tuple<int, int, int>> q;
        int mini = 0;

        for(int r=0; r<grid.size(); r++) {
            for(int c=0; c<grid[r].size(); c++) {
                if(grid[r][c] == 2)
                    q.push({r, c, 0});
            }
        }

        while(!q.empty()) {
            auto [row, col, cost] = q.front();
            q.pop();
            /*
            1,0
            -1,0
            0,1
            0,-1
            */

            vector<int> dr = {1, -1, 0, 0};
            vector<int> dc = {0, 0, 1, -1};            

            for(int k=0; k<4; k++) {
                int nr = dr[k] + row;
                int nc = dc[k] + col;
                mini = max(mini, cost);

                if((nr < 0) || (nc < 0) || (nr >= grid.size()) || (nc >= grid[nr].size()))
                    continue;

                if(grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    q.push({nr, nc, cost+1});
                }
            }
        }

        for(int r=0; r<grid.size(); r++) {
            for(int c=0; c<grid[r].size(); c++) {
                if(grid[r][c] == 1)
                    return -1;
            }
        }

        return mini;
    }


    int orangesRotting(vector<vector<int>>& grid) {
        return bfs(grid);
    }
};
