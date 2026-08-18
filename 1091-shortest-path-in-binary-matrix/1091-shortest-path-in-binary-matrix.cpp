class Solution {
public:
    using inn=pair<int,pair<int,int>>;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        if(grid[0][0]!=0 || grid[n-1][m-1]!=0)return -1;
        queue<inn>pq;
        int dx[]={-1,1,0,0,-1,1,-1,1};
        int dy[]={0,0,-1,1,-1,-1,1,1};
        pq.push({1,{0,0}});
        dist[0][0]=1;
        while(!pq.empty()){
            auto tp=pq.front();pq.pop();
            int d=tp.first;
            int row=tp.second.first;
            int col=tp.second.second;
            for(int i=0;i<8;i++){
                int nx=row+dx[i];
                int ny=col+dy[i];
                 if(nx<0 || ny<0 || nx>=n || ny>=m || grid[nx][ny]==1)continue;
                 if(dist[nx][ny]>d+1){
                    dist[nx][ny]=d+1;
                    pq.push({dist[nx][ny],{nx,ny}});
                 }
            }
        }
        return dist[n-1][m-1]==INT_MAX?-1:dist[n-1][m-1];
    }
};