class Solution {
public:

    void dfs(vector<vector<char>>& grid, int row, int col) {
        if(grid[row][col] != 'O')
            return;
        cout<<row<<" "<<col<<endl;
        grid[row][col] = 'M';

        vector<int> dr = {1,-1,0,0}; 
        vector<int> dc = {0,0,1,-1};

        for(int k=0; k<4; k++) {
            int nr = dr[k] + row;
            int nc = dc[k] + col;

            if((nr >= grid.size()) || (nc >= grid[nr].size()))
                continue;
            if(grid[nr][nc] != 'O')
                continue;
            dfs(grid, nr, nc);
        }
    }


    void solve(vector<vector<char>>& grid) {
        //row = 0
        for(int c=0; c<grid[0].size(); c++)
            dfs(grid, 0, c);
        //row = n-1
        for(int c=0; c<grid[0].size(); c++)
            dfs(grid, grid.size()-1, c);

        //col = 0
        for(int r=0; r<grid.size(); r++)
            dfs(grid, r, 0);

        //col = n-1
        for(int r=0; r<grid.size(); r++)
            dfs(grid, r, grid[0].size()-1);

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
