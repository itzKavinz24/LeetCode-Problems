class Solution{
public:
    using PII=pair<long long,int>;
    const int mod=1e9+7;


    int countPaths(int n,vector<vector<int>>& roads){
        vector<vector<pair<int,int>>>adj(n);

        for(auto &r:roads){
            int u=r[0];
            int v=r[1];
            int w=r[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        vector<long long>dist(n,LLONG_MAX);
        vector<int>ways(n,0);
        priority_queue<PII,vector<PII>,greater<PII>>pq;

        dist[0]=0;
        ways[0]=1;
        pq.push({0,0});
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();

            long long d=top.first;
            int node=top.second;

            if(d>dist[node])continue;

            for(auto &p:adj[node]){
                int nei=p.first;
                int wt=p.second;

                if(d+wt<dist[nei]){
                    dist[nei]=d+wt;
                    ways[nei]=ways[node];
                    pq.push({dist[nei],nei});
                }
                
                else if(d+wt==dist[nei]){
                    ways[nei]=(ways[nei]+ways[node])%mod;
                }
            }
        }
        return ways[n-1];
    }
};