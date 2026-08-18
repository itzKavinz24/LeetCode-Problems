class Solution {
public:
    using inn = pair<int, pair<int, int>>;
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> res(n, vector<int>(m, INT_MAX));
        priority_queue<inn, vector<inn>, greater<inn>> pq;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    res[i][j] = 0;
                    pq.push({0, {i, j}});
                }
            }
        }
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            int d = p.first;
            int x = p.second.first;
            int y = p.second.second;
            if (d > res[x][y])
                continue;
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    if (res[nx][ny] > d + 1) {
                        res[nx][ny] = d + 1;
                        pq.push({res[nx][ny], {nx, ny}});
                    }
                }
            }
        }
        return res;
    }
};