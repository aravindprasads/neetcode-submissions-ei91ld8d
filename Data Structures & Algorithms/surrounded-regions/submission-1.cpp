// Find all Os
// For each O - replace with M and do DFS - 
    // find neighbor Os. Not Ms or Xs
// Replace Ms with O and O with X



class Solution {
public:

    void dfs(vector<vector<char>>& grid, int r, int c) {
        if(grid[r][c] != 'O')
            return;
        
        grid[r][c] = 'M';

        vector<int>dr = {1,-1,0,0};
        vector<int>dc = {0,0,1,-1};

        for(int k=0; k<4; k++) {
            int nr = dr[k] + r;
            int nc = dc[k] + c;

            if((nr < 0) || (nr >= grid.size()) || (nc < 0) || (nc >= grid[nr].size()))
                continue;
            if(grid[nr][nc] != 'O')
                continue;            
            dfs(grid, nr, nc);
        }
    }

    void solve(vector<vector<char>>& grid) {
        if(grid.size() == 0)
            return;

        //top
        int r = 0;
        for(int c=0; c<grid[0].size(); c++) {
            if(grid[r][c] == 'O') {                
                dfs(grid, r, c);
            }
        }

        //left
        int c=0;
        for(int r=0; r<grid.size(); r++) {
            if(grid[r][c] == 'O') {                
                dfs(grid, r, c);
            }
        }

        //right
        c = grid[0].size()-1;
        for(int r=0; r<grid.size(); r++) {
            if(grid[r][c] == 'O') {                
                dfs(grid, r, c);
            }
        }

        //bottom
        r = grid.size()-1;
        for(int c=0; c<grid[0].size(); c++) {
            if(grid[r][c] == 'O') {                
                dfs(grid, r, c);
            }
        }


        for(int r=0; r<grid.size(); r++) {
            for(int c=0; c<grid[r].size(); c++) {
                if(grid[r][c] == 'O')
                    grid[r][c] = 'X';

                if(grid[r][c] == 'M')
                    grid[r][c] = 'O';                
            }
        }
    }
};
