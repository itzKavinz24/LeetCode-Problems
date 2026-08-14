class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        int n = routes.size();
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        queue<pair<int,int>> pq;
        map<int,set<int>> freq;
        for(int i = 0; i < routes.size(); i++){
            for(int j = 0; j < routes[i].size(); j++){
                int stop = routes[i][j];
                if(stop == source){
                    visited[i] = true;
                    pq.push({1, i});
                }
                if(freq.find(stop) != freq.end()){
                    for(auto p : freq[stop]){
                        adj[p].push_back(i);
                        adj[i].push_back(p);
                    }
                }
                freq[stop].insert(i);
            }
        }
        while(!pq.empty()){
            auto p = pq.front();
            pq.pop();
            int count = p.first;
            int bus = p.second;
            if(freq[target].count(bus)){
                return count;
            }
            for(auto &p : adj[bus]){
                if(visited[p] == false){
                    visited[p] = true;
                    pq.push({count + 1, p});
                }
            }
        }
        return -1;
    }
};