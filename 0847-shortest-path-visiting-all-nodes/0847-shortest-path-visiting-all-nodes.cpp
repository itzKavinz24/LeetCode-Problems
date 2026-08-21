class Solution {
public:
    int n;

    int shortestPathLength(vector<vector<int>>& graph) {
        n = graph.size();
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(n, vector<bool>(1 << n, false));

        for(int i = 0; i < n; i++) {
            int mask = (1 << i);
            q.push({i, mask});
            visited[i][mask] = true;
        }
        int steps = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {

                auto top = q.front();
                q.pop();
                int node = top.first;
                int mask = top.second;

                if(mask == (1 << n) - 1)
                    return steps;

                for(int p : graph[node]) {

                    int newMask = mask | (1 << p);
                    if(!visited[p][newMask]) {
                        visited[p][newMask] = true;
                        q.push({p, newMask});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};