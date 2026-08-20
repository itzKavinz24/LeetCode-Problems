class Solution {
public:
    unordered_map<string, vector<string>> mp;
    vector<vector<string>> ans;
    vector<string> path;

    void dfs(string word, string start) {
        path.push_back(word);
        if (word == start) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            path.pop_back();
            return;
        }

        for (auto &p : mp[word]) {
            dfs(p, start);
        }
        path.pop_back();
    }

    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());

        if (!st.count(endWord))
            return {};
        queue<string> q;
        q.push(beginWord);
        bool found = false;
        while (!q.empty() && !found) {

            int s = q.size();
            unordered_set<string> temp;
            while (s--) {
                string j = q.front();
                q.pop();

                string og = j;

                for (int i = 0; i < j.size(); i++) {
                    char init = j[i];

                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == init)
                            continue;
                        j[i] = c;
                        if (!st.count(j))
                            continue;

                        if (!temp.count(j)) {
                            temp.insert(j);
                            q.push(j);
                        }
                        mp[j].push_back(og);

                        if (j == endWord)
                            found = true;
                    }
                    j[i] = init;
                }
            }
            for (auto &p : temp)
                st.erase(p);
        }
        if (found)
            dfs(endWord, beginWord);

        return ans;
    }
};