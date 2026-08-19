class Solution {
public:
    using inn=pair<string,double>;
    map<string,vector<inn>>mp;
    double dfs(string src, string des) {
    if(mp.find(src)==mp.end() || mp.find(des)==mp.end())
        return -1.0;
    if(src==des)
        return 1.0;
    queue<pair<double,string>> q;
    unordered_set<string> vis;
    q.push({1.0, src});
    vis.insert(src);
    while(!q.empty()) {
        auto top = q.front();
        q.pop();
        double value = top.first;
        string node = top.second;
        if(node==des)
            return value;
        for(auto k : mp[node]) {
            string next = k.first;
            double wt = k.second;
            if(vis.count(next))
                continue;
            vis.insert(next);
            q.push({value*wt, next});
        }
    }

    return -1.0;
}
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        vector<double>res(queries.size(),0.0);

        for(int i=0 ;i < equations.size(); i++ ){
            string first=equations[i][0];
            string second=equations[i][1];
            double value = values[i];

            mp[first].push_back({second,value});
            mp[second].push_back({first,1/value});
        }
        
        for(int i=0;i<queries.size(); i++ ){
            double ans=dfs(queries[i][0],queries[i][1]);
            res[i]=ans;
        }
        return res;
         
    }
};