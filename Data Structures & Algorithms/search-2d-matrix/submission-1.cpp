/*
 rows, cols
m, n

10

row = x/4
col = x%4k
*/


class Solution {
public:

    int getEle(vector<vector<int>>grid, int index) {
        int rows = grid.size();
        int cols = grid[0].size();

        int r = index/cols;
        int c = index%cols;

        if(r<0 || r>=rows)
            return INT_MAX;
        if(c<0 || c>=cols)
            return INT_MAX;

        return grid[r][c];
    }

    bool bs(vector<vector<int>>grid, int target, int low, int high) {
        while(low <= high) {
            int mid = (low + high)/2;
            int ele = getEle(grid, mid);
            if(ele == target)
                return true;
            if(ele > target)
                high = mid-1;
            else
                low = mid+1;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return bs(matrix, target, 0, (matrix.size()*matrix[0].size())-1);
    }
};
