class Solution {
public:
    using PII=pair<int,int>;
    using inn=pair<int,PII>;
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        priority_queue<inn,vector<inn>,greater<inn>>pq;
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=grid[0][0];
        pq.push({grid[0][0],{0,0}});
        
        int dirx[4]={-1,1,0,0};
        int diry[4]={0,0,-1,1};
        while(!pq.empty()){
            auto p=pq.top();pq.pop();
            int absol=p.first;
            int row=p.second.first;
            int col=p.second.second;
            for(int i=0;i<4;i++){
                int nx=row+dirx[i];
                int ny=col+diry[i];
                if(nx>=0 && ny>=0 && nx<n && ny<m ){
                    int effort=max(absol,grid[nx][ny]);
                    if(effort<dist[nx][ny]){
                        dist[nx][ny]=effort;
                        pq.push({dist[nx][ny],{nx,ny}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};