class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>last(26,0);
        int n = s.size();
        for(int i=0;i<s.size();i++){
            last[s[i]-'a'] = i;
        }
        vector<int>res;
        int end=0;
        int start =0;
        for(int i=0;i<s.size();i++){
            end = max(end,last[s[i]-'a']);
            if(end==i){
                res.push_back(end-start+1);
                start = i + 1;
            }
        }
        return res;

    }
};