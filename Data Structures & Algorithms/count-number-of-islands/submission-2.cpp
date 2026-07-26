/*0,0

0,1
0,-1
1,0
-1,0
*/

class Solution {
public:

    void bfs(vector<vector<char>>grid, unordered_set<string>& visited, int row, int col) {
        string key = to_string(row) + "," + to_string(col);
        if(visited.find(key) != visited.end())
            return;

        visited.insert(key);

        vector<int> dr = {0,0,1,-1};
        vector<int> dc = {1,-1,0,0};

        for(int k=0; k<4; k++) {
            int nr = dr[k] + row;
            int nc = dc[k] + col;

            if((nr < 0) || (nr >= grid.size()))
                continue;
            if((nc < 0) || (nc >= grid[row].size()))
                continue;

            if(grid[nr][nc] == '0')
                continue;

            bfs(grid, visited, nr, nc);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0)
            return 0;

        unordered_set<string> visited;        
        int cnt = 0;

        for(int r=0; r<grid.size(); r++) {
            for(int c=0; c<grid[r].size(); c++) {
                string key = to_string(r) + "," +  to_string(c);
                if(grid[r][c] == '0')
                    continue;
                if (visited.find(key) != visited.end())
                    continue;
                bfs(grid, visited, r, c);
                cnt++;
            }
        }

        return cnt;
    }
};
