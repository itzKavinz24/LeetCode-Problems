class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n + 1);
        for (auto &edge : dislikes) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<int> colors(n + 1, -1);
        for (int i = 1; i <= n; i++) {
            if (colors[i] != -1) continue;
            queue<pair<int, int>> pq;
            pq.push({0, i});
            colors[i] = 0;
            while (!pq.empty()) {
                auto p = pq.front();
                pq.pop();
                int color = p.first;
                int node = p.second;
                for (int neighbour : graph[node]) {
                    if (colors[neighbour] == -1) {
                        colors[neighbour] = 1 - color;
                        pq.push({1 - color, neighbour});
                    } else if (colors[neighbour] == color) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};