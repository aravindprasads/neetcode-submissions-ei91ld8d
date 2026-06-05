class Solution {

int getVal(int index, vector<vector<int>> grid) {
    int cols = grid[0].size();
    int r = index/cols;
    int c = index%cols;
    return grid[r][c];
}

bool binSearch(int low, int high, vector<vector<int>> grid, int target) {
    while(low <= high) {
        int mid = (low+high)/2;
        int val = getVal(mid, grid);
        if(val == target)
            return true;
        if(val > target) {
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    return false;
}


public:
    bool searchMatrix(vector<vector<int>>& grid, int target) {
        int rows = grid.size();
        int cols = grid[0].size();
        int num = rows*cols;
        return binSearch(0, num-1, grid, target);        
    }
};
