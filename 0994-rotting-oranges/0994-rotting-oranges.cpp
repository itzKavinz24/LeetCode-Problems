class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> pq;
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    pq.push({i,j});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        if(fresh == 0) return 0;
        int minutes = 0;
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        while(!pq.empty() && fresh > 0){
            int sz = pq.size();
            while(sz--){
                pair<int,int> p = pq.front();
                pq.pop();
                int row = p.first;
                int col = p.second;
                for(int i = 0; i < 4; i++){
                    int nx = row + dx[i];
                    int ny = col + dy[i];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m)
                        continue;
                    if(grid[nx][ny] == 1){
                        grid[nx][ny] = 2;
                        fresh--;
                        pq.push({nx,ny});
                    }
                }
            }
            minutes++;
        }
        if(fresh > 0)
            return -1;
        return minutes;
    }
};