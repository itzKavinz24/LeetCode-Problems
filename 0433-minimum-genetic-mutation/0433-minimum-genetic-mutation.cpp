class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        if(startGene == endGene)
            return 0;
        unordered_set<string> st(bank.begin(), bank.end());
        if(!st.count(endGene))
            return -1;
        vector<char> ch = {'A','C','G','T'};
        queue<pair<int,string>> q;
        q.push({0, startGene});
        while(!q.empty()){
            auto [steps, gene] = q.front();
            q.pop();
            if(gene == endGene)
                return steps;
            for(int i = 0; i < 8; i++){
                char old = gene[i];
                for(char c : ch){
                    gene[i] = c;
                    if(st.count(gene)){
                        q.push({steps + 1, gene});
                        st.erase(gene);
                    }
                }
                gene[i] = old;
            }
        }

        return -1;
    }
};