class Solution {
public:
    using PII = pair<int, int>;
    using inn = pair<int, PII>;

    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {
        vector<vector<PII>> adj(n);
        for (auto &p : flights) {
            adj[p[0]].push_back({p[2], p[1]});
        }
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        queue<inn> pq;
        pq.push({0, {0, src}});
        while (!pq.empty()) {
            int sz = pq.size();
            vector<int> temp = dist;
            while (sz--) {
                auto l = pq.front();
                pq.pop();
                int stops = l.first;
                int distan = l.second.first;
                int node = l.second.second;
                if (stops > k)
                    continue;
                for (auto &j : adj[node]) {

                    int dist2 = j.first;
                    int node2 = j.second;

                    if (distan + dist2 < temp[node2]) {

                        temp[node2] = distan + dist2;

                        pq.push({stops + 1, {temp[node2], node2}});
                    }
                }
            }

            dist = temp;
        }

        if (dist[dst] == INT_MAX)
            return -1;

        return dist[dst];
    }
};