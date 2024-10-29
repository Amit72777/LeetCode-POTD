class Solution {
    int solve(int row, int col, vector<vector<int>>& grid,
              vector<vector<int>>& dp, int m, int n) {
        if (row >= m   || col >= n )
            return 0;

        if (dp[row][col] != -1) 
            return dp[row][col];
        int upright ,right,downright;
         upright = right = downright = -1;
        if (row > 0 && col < n - 1   && grid[row][col] < grid[row - 1][col + 1]) {
            upright = solve(row - 1, col + 1, grid, dp, m, n);  
        }
        if (  col < n-1 && grid[row][col] < grid[row][col + 1]) {
            right = solve(row, col + 1, grid, dp, m, n);
        }
        if (  row < m - 1 && col < n-1  &&
            grid[row][col] < grid[row + 1][col + 1]) {
            downright = solve(row + 1, col + 1, grid, dp, m, n);
        }

        return dp[row][col]= max(upright, max(downright, right)) + 1;
    }

public:
    int maxMoves(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> dp(row,vector<int>(col,-1));
        int ans = 0;
        for (int i = 0; i < row ; i++) {  // move 1st column only 
            int tem = solve(i, 0, grid, dp, row, col);
            ans = max(ans, tem);
        }
        return ans;
    }
};
