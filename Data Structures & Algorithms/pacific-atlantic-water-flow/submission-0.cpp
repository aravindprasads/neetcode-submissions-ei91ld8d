class Solution {
public:

    void dfs(vector<vector<int>> grid, 
             int row, int col, 
             vector<vector<int>>& visited) {             

        if(visited[row][col] !=  -1)
            return;
        
        visited[row][col] = 1;

        vector<int> dr = {1,-1,0,0};
        vector<int> dc = {0,0,1,-1};

        for(int k=0; k<4; k++) {
            int nr = row + dr[k];
            int nc = col + dc[k];

            if(nr >= grid.size() || nc >= grid[nr].size())
                continue;

            if(grid[row][col] > grid[nr][nc])
                continue;

            dfs(grid,nr, nc, visited);
        }
    }

    vector<vector<int>> get_visited_grid(int m, int n) {        
        vector<vector<int>> ans;
        
        int c = 0;
        while(c < m) {
            vector<int>col(n, -1);            
            ans.push_back(col);
            c++;
        }

        return ans;
    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {

        vector<vector<int>> at = get_visited_grid(grid.size(), grid[0].size());
        //top
        for(int c=0; c<grid[0].size(); c++)
            dfs(grid, 0, c, at);
        //left
        for(int r=0; r<grid.size(); r++)
            dfs(grid, r, 0, at);

        vector<vector<int>> pac = get_visited_grid(grid.size(), grid[0].size());
        //bottom
        for(int c=0; c<grid[0].size(); c++)
            dfs(grid, grid.size()-1, c, pac);
        //right
        for(int r=0; r<grid.size(); r++)
            dfs(grid, r, grid[0].size()-1, pac);

        vector<vector<int>> ans;
        for(int r=0; r<grid.size(); r++) {
            for(int c=0; c<grid[r].size(); c++) {
                if((at[r][c] == 1) && (pac[r][c] == 1))
                    ans.push_back({r,c});
            }
        }
        return ans;
    }
};