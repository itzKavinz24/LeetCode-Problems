class Solution {
public:
    int longestValidParentheses(string s) {
        int n =s.size();
        vector<int>dp(n,0);
        stack<int>st;
        int ans = 0;

        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }else{
                if(st.empty())continue;
                
                int open =st.top();
                st.pop();

                int length = i-open + 1;
                dp[i]=length;
                if(open>0){
                    dp[i]+=dp[open-1];
                }
                ans = max(ans,dp[i]);
            }
        }
        return ans;
    }
};