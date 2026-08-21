class Solution {
public:
    unordered_set<int> restrictedSet;

    int dfs(int node, int parent, vector<vector<int>>& adj) {
        if (restrictedSet.count(node))
            return 0;

        int cnt = 1;

        for (int nei : adj[node]) {
            if (nei != parent) {
                cnt += dfs(nei, node, adj);
            }
        }

        return cnt;
    }

    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        for (int x : restricted)
            restrictedSet.insert(x);

        return dfs(0, -1, adj);
    }
};