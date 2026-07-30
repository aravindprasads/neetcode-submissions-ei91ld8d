class Solution {
public:

    void dfs(unordered_set<string>& visited, vector<vector<int>> grid, int row, int col) {
        string key = to_string(row) + "," + to_string(col);
        if(visited.find(key) != visited.end())
            return;
        visited.insert(key);
                
        vector<int> dr = {1, -1, 0, 0};
        vector<int> dc = {0, 0, 1, -1};

        for(int k=0; k<4; k++) {
            int nr = dr[k] + row;
            int nc = dc[k] + col;

            if((nr<0) || (nc<0) || (nr >= grid.size()) || (nc >= grid[nr].size()))
                continue;
            
            if(grid[nr][nc] >= grid[row][col])
                dfs(visited, grid, nr, nc);
        }
    }

    vector<vector<int>> findUnion(unordered_set<string> pac, unordered_set<string> at) {
        vector<vector<int>> res;
        for(auto it:pac) {
            if(at.find(it) != at.end()) {
                int i=0;
                string row_s = "";
                while(it[i] != ',') {
                    row_s += it[i];
                    i++;
                }
                int row = stoi(row_s);
                i++;
                string col_s = "";
                while(i < it.length()) {
                    col_s += it[i];
                    i++;
                }
                int col = stoi(col_s);

                res.push_back({row, col});
            }
        }
        return res;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        // Pacific - top and left
        // Atlantic - bottom adn right

        unordered_set<string> pac_set, at_set;

        //Pacific
        for(int c=0; c<grid[0].size(); c++)
            dfs(pac_set, grid, 0, c);
        for(int r=0; r<grid.size(); r++)
            dfs(pac_set, grid, r, 0);

        //Atlantic
        for(int c=0; c<grid[0].size(); c++)
            dfs(at_set, grid, grid.size()-1, c);
        for(int r=0; r<grid.size(); r++)
            dfs(at_set, grid, r, grid[0].size()-1);

        return findUnion(pac_set, at_set);        
    }
};
