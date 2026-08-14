class Solution {
public:
    using PII=pair<double,int>;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {

            vector<vector<PII>>adj(n);
            priority_queue<PII>pq;
            int count=0;
            for(auto &p:edges){
                int a=p[0];
                int b=p[1];
                double num=succProb[count];
                adj[a].push_back({num,b});
                adj[b].push_back({num,a});
                count++;
            }
            vector<double>dist(n,0.0);
        dist[start_node]=1.0;
        pq.push({1.0,start_node});
        while(!pq.empty()){
            auto p=pq.top();pq.pop();
            double prob=p.first;
            int node=p.second;
            for(auto &j: adj[node]){
                double dist2 = j.first;
                int node2 = j.second;
                if(prob*dist2>dist[node2]){

                    dist[node2]=(double)prob*dist2;  

                    pq.push( { dist[ node2 ],node2} );                    
                }
            }
        }
        if(dist[end_node]==0.0)return 0.0;
        return dist[end_node];
    }
};