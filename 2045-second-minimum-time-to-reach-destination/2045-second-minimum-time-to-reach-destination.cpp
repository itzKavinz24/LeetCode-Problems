class Solution {
public:
    using inn=pair<int,int>;
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>>adj(n+1);
        vector<vector<int>>d(n+1,vector<int>(2,INT_MAX));
        for(int i=0;i<edges.size();i++){
            int first=edges[i][0];
            int second=edges[i][1];
            adj[first].push_back(second);
            adj[second].push_back(first);
        }
        priority_queue<inn,vector<inn>,greater<inn>>pq;
        pq.push({0,1});
        d[1][0] =0;

        while(!pq.empty()){
            auto tp=pq.top();pq.pop();
            int first=tp.first;
            int second=tp.second;
           if ((first / change) % 2 == 1) {
            first = (first / change + 1) * change;
            }
            for(int p:adj[second]){
                if(d[p][0] > first + time ){
                    d[p][1] = d[p][0];
                    d[p][0]= first + time;
                     pq.push({first + time, p });
                }
                else if( d[p][0] < first  + time && d[p][1] > first + time ){
                    d[p][1] = first + time;
                    pq.push({ first + time   , p });
                }
            }
        }
        return d[n][1];
    }
};