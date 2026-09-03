class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if (s.size() < p.size())
            return res;
        int m = p.size();
        int n = s.size();
        unordered_map<char, int> freq1, freq2;
        for (char c : p) {
            freq1[c]++;
        }
        for (int i = 0; i < m; i++) {
            freq2[s[i]]++;
        }
        if (freq1 == freq2) {
            res.push_back(0);
        }
        for (int r = m; r < n; r++) {
            freq2[s[r]]++;
            freq2[s[r - m]]--;
            char c = s[r - m];
            if (freq2[c] == 0) {
                freq2.erase(c);
            }
            if (freq1 == freq2) {
                res.push_back(r - m + 1);
            }
        }
       return res;
    }
};