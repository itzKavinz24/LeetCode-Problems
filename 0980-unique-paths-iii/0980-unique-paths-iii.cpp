class Solution {
public:
    pair<int,int>start;
    pair<int,int>end;
    int n,m;
    
    int rec(int i,int j ,vector<vector<int>> &grid,int mask){
        
        if(i>=n || j>=m || i<0 || j<0)return 0;

        int ind = i * m + j;
        if(mask & (1<<ind))return 0;
        mask = mask | (1 << ind);

        if( i==end.first && j==end.second){
            if(mask == (1<< n*m)-1) return 1;
            return 0;
        }
        //for setting th index bit o visited
        
        int dx[] ={-1,1,0,0};
        int dy[] = {0,0,-1,1};
        int ans = 0 ;
        for(int x=0;x<4;x++){
            int nx = i + dx[x];
            int ny = j + dy[x];
            ans += rec(nx,ny,grid,mask);
        }
        return ans;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
         n =grid.size();
         m = grid[0].size();
        int mask = 0;
        for(int i = 0 ; i < n ; i++ ){
            for(int j = 0 ; j < m ; j++){
                int ind = i * m + j;
                if(grid[i][j]==1){
                    start={i,j};
                }
                else if( grid[i][j] == 2){
                    end = {i,j};
                }
                else if( grid[i][j] == -1){
                     mask = mask | (1 << ind);
                }
            }
        }
        return rec( start.first,start.second,grid,mask);
    }
};