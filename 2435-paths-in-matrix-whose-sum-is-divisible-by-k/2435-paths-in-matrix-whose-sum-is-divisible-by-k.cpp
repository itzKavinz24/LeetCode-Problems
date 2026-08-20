class Solution {
public:
    int n, m;
    const int mod = 1e9 + 7;
    vector<vector<vector<int>>> dp;
    int rec(int i, int j, int rem, int k, vector<vector<int>>& grid) {
        if (i >= n || j >= m)
            return 0;
        rem = (rem + grid[i][j]) % k;
        if (i == n - 1 && j == m - 1)
            return (rem == 0);
        if (dp[i][j][rem] != -1)
            return dp[i][j][rem];

        long long down = rec(i + 1, j, rem, k, grid);
        long long right = rec(i, j + 1, rem, k, grid);

        return dp[i][j][rem] = (down + right) % mod;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        dp.assign(n, vector<vector<int>>(m, vector<int>(k, -1)));
        return rec(0, 0, 0, k, grid);
    }
};