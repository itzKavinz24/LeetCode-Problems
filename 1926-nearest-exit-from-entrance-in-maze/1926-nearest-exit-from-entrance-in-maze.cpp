class Solution {
public:
    using inn=pair<int,pair<int,int>>;
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n =maze.size();
        int m=maze[0].size();
        queue<inn>q;
        q.push({0,{entrance[0],entrance[1]}});

        vector<vector<int>>dist( n , vector<int> (m, INT_MAX ));

        dist[ entrance[0]][entrance[1]]=0;

         int dx[4] = { -1 , 1 , 0 , 0 };
         int dy[4] = {  0 , 0 ,-1 , 1 } ;
        while(!q.empty()){
            auto top = q.front(); q.pop();
            int d=top.first;
            int row = top.second.first;
            int col = top.second.second;

            //Checking for the edge
            if( row != entrance[0]  ||  col != entrance[1])
            if( row + 1 >= n || col + 1 >=m  || row - 1 < 0 || col - 1 < 0){
                return d;
            }

            for( int i = 0 ; i < 4 ; i++){
                int  nx = row + dx[i];
                int  ny = col + dy[i];

                if( nx >= n  ||  ny >= m || nx < 0 || ny < 0 )continue;

                if(maze[nx][ny]!='+' &&  dist[nx][ny] > d + 1 ){

                    dist[nx][ny] = d + 1;
                    q.push({dist[nx][ny],{nx,ny}});

                }
            }
        }
        return -1;
    }
};