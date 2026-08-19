class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& preq) {
        vector<int>indeg(n,0);
        // vector<int>present(n,false);
        unordered_map<int,vector<int>>mp;
        for(auto &p:preq){
            int next=p[0];
            int now=p[1];
            // present[next]=true;
            // present[now]=true;
            indeg[next]++;
            mp[now].push_back(next);
        }

        queue<int>q;

        for(int i=0;i<n;i++){
            if(indeg[i]==0 ){
                q.push(i);
            }
        }
        vector<int>res;
        while(!q.empty()){
            int num=q.front();q.pop();
            res.push_back(num);
            for(int nu:mp[num]){
                indeg[nu]--;
                if(indeg[nu]==0){
                    q.push({nu});
                }
            }
        }
        if(n==res.size()){
            return res;
        }
        return {};

    }
};