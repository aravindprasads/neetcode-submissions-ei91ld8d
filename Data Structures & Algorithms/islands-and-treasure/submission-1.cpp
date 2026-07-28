//BFS
//Find all treasure positions
//start BFS - put them in queue and iterate
//consider only INF positions

class Solution {
public:

    void bfs(vector<vector<int>>& grid, queue<tuple<int, int, int>> q) {
        while(!q.empty()) {
            auto [row, col, cost] = q.front();
            q.pop();

            /*
            0,0

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

                if((nr<0) || (nr >= grid.size()) || (nc < 0) || (nc >= grid[nr].size()))
                    continue;                

                if(grid[nr][nc] == 2147483647) {
                    q.push({nr, nc, cost+1});
                    grid[nr][nc] = cost+1;
                }
            }
        }
    }


    void islandsAndTreasure(vector<vector<int>>& grid) {

        if (grid.size() == 0)
            return;

        queue<tuple<int, int, int>> q;        

        for(int r=0; r<grid.size(); r++) {
            for(int c=0; c<grid[r].size(); c++) {
                if(grid[r][c] == 0)
                    q.push({r,c, 0});
            }
        }
        if(!q.empty())
            bfs(grid, q);
    }
};
