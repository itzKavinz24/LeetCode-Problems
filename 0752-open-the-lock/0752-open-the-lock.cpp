class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        string start="0000";
        vector<char>cs{'0','1','2','3','4','5','6','7','8','9'};
        queue<pair<int ,string >>q;

         unordered_set <string>st(deadends.begin() ,deadends.end() );
         unordered_set<string>vis;
        q.push({0,start});
        vis.insert(start);
        if(st.count(start))return -1;
        while(!q.empty()){
            auto tp=q.front();q.pop();
            int count =tp.first;
            string top=tp.second;

            if( top == target){
                return count;
            }
            for(int i=0; i < 4 ;i++ ){
                 char old=top[i];
                top[i] = ((old - '0' + 1) % 10) + '0';
                if(!st.count(top) && !vis.count(top)){
                    vis.insert(top);
                    q.push({count+1,top});
                }
                top[i] = ((old - '0' + 9) % 10) + '0';
                if(!st.count(top) && !vis.count(top)){
                    vis.insert(top);
                    q.push({count+1,top});
                   
                }
                top[i]=old;
                 
            }
        }
        return -1;
    }
};