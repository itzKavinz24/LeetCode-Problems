class Solution {
public:
    vector<vector<vector<int>>> dp;
    int n, m;

    int rec(int row, int col, int col2, vector<vector<int>> &grid) {
        int row2 = row + col - col2;
        if (row >= n || col >= m || row2 >= n || col2 >= m)
            return -1e9;
        
        if (grid[row][col] == -1 || grid[row2][col2] == -1)
            return -1e9;

        if (row == n - 1 && col == m - 1)
            return grid[row][col];

        if (dp[row][col][col2] != -1)
            return dp[row][col][col2];

        int cherries = grid[row][col];

        if (row != row2 || col != col2)
            cherries += grid[row2][col2];

        int rr = rec(row, col + 1, col2 + 1, grid);
        int rd = rec(row, col + 1, col2, grid);
        int dr = rec(row + 1, col, col2 + 1, grid);
        int dd = rec(row + 1, col, col2, grid);

        int best = max({rr, rd, dr, dd});

        return dp[row][col][col2] = cherries + best;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        dp.assign(n, vector<vector<int>>(m, vector<int>(m, -1)));

        return max(0, rec(0, 0, 0, grid));
    }
};