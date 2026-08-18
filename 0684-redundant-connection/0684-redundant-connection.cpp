class Solution {
public:
    vector<int> parent;

    int find(int x){
        if(parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        for(int i = 1; i <= n; i++)
            parent[i] = i;
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int pu = find(u);
            int pv = find(v);
            if(pu == pv)
                return e;
            parent[pv] = pu;
        }

        return {};
    }
};