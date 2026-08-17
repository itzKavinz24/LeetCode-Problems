class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>pq;
        unordered_map<string,bool>mp;
        for(string words:wordList){
            mp[words]=true;
           }
        pq.push({beginWord,1});
        while(!pq.empty()){
            auto t=pq.front();pq.pop();
            string word=t.first;
            int count=t.second;
            if(word==endWord){
                return count;
            }
            for(int i=0;i<word.size();i++){
                char init =word[i];
                for(int j=0;j<26;j++){
                    word[i]= j+'a';
                    if(mp.find(word)!=mp.end() && mp[word]==true){
                        mp[word]=false;
                        pq.push({word,count+1});
                    }
                    word[i]=init;
                }
            }
        }
        return 0;
    }
};